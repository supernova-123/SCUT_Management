'''
Author: error: git config user.name && git config user.email & please set dead value or install git
Date: 2022-05-14 10:21:08
LastEditors: error: git config user.name && git config user.email & please set dead value or install git
LastEditTime: 2022-06-07 13:19:27
FilePath: \【python学习】\GetTodayData.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import requests
import pandas as pd
import time
import json
pd.options.display.max_rows = 500
headers = {
    'user-agent' : 'Mozilla/5.0 (Windows NT 6.1; Win64; x64)AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.149 Safari/537.36'
}
url = 'https://c.m.163.com/ug/api/wuhan/app/data/list-total'   # 定义要访问的地址
r = requests.get(url, headers=headers)  # 使用requests发起请求
#print(r.status_code)  # 查看请求状态
#print(type(r.text))
#print(len(r.text))
data_json = json.loads(r.text)
data_json.keys()
data = data_json['data']
data.keys()
data_province = data['areaTree'][2]['children']# 取出中国各省的实时数据
type(data_province)
data_province[0].keys()#查看每个省键名称
# for i in range(len(data_province)): # 遍历查看各省名称、更新时间
#     print(data_province[i]['name'],data_province[i]['lastUpdateTime'])
#     if i == 5:
#         break

# 获取id、lastUpdateTime、name
info = pd.DataFrame(data_province)[['id','lastUpdateTime','name']]
info.head()

# 获取today中的数据
today_data = pd.DataFrame([province['today'] for province in data_province ]) 
today_data.head()
['today_'+i for i in today_data.columns]
today_data.columns = ['today_'+i for i in today_data.columns] # 由于today中键名和total键名相同，因此需要修改列名称
today_data.head()

# 获取total中的数据
total_data = pd.DataFrame([province['total'] for province in data_province ])
total_data.columns = ['total_'+i for i in total_data.columns]#加个后缀
total_data.head()

pd.concat([info,total_data,today_data],axis=1).head() # 将三个数据合并

# 将提取数据的方法封装为函数
def get_data(data,info_list):
    info = pd.DataFrame(data)[info_list] # 主要信息
    
    today_data = pd.DataFrame([i['today'] for i in data ]) # 生成today的数据
    today_data.columns = ['today_'+i for i in today_data.columns] # 修改列名
    
    
    return pd.concat([info,total_data,today_data],axis=1) # info、today和total横向合并最终得到汇总的数据
today_province = get_data(data_province,['id','lastUpdateTime','name'])
today_province.head()

def save_data(data,name): # 定义保存数据方法
    file_name = name+'_'+'.csv'
    data.to_csv(file_name,index=None,encoding='utf_8_sig')
    print(file_name+' 保存成功！')
    
time.strftime('%Y_%m_%d',time.localtime(time.time()))
save_data(today_province,'today_province')