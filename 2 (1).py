# -*- coding: utf-8 -*-
import jieba

py = 0.1;#先验概率
p_a_y_dic = {};#储存p(a|y)
dic = {};#总词频
count = 0.0;

y_label = ['C000007','C000008','C000010','C000013','C000014','C000016','C000020','C000022','C000023','C000024'];
x_sample_name = range(10,20);
for label in y_label:
    p_a_y_dic_list_dic = {};#储存p(a|y)
    for name in x_sample_name:
        path = "./" + label + "/" + str(name) + ".txt";
        fp = open(path,'r')
        lines=fp.readlines();
        data = "".join(lines);
        seg_list = jieba.cut(data);
        #print ("/ ".join(seg_list))
        
        for seg in seg_list:
            #更新总词频
            count = count + 1 ;
            if dic.has_key(seg):
                dic[seg] = dic[seg] +1;
            else:
                dic[seg] = 1;
            #更新p(a|y)
            if p_a_y_dic_list_dic.has_key(seg):
                p_a_y_dic_list_dic[seg] = p_a_y_dic_list_dic[seg] +1;
            else:
                p_a_y_dic_list_dic[seg] = 1;            
            
        print(path+"\n");
    for key,value in p_a_y_dic_list_dic.items():
        p_a_y_dic_list_dic[key] = value / count;
    p_a_y_dic[label]=p_a_y_dic_list_dic;#储存p(a|y)

dic_str = "";
#for key,value in dic.items():
    #dic_str = dic_str + "\"%s\":\"%s\"\n"%(key,value)
#print(dic_str)

#输出词频p_a_y_dic
for key,value in p_a_y_dic.items():
    for key_in,value_in in p_a_y_dic[key].items():
        dic_str = dic_str +  "%s\"%s\":\"%s\"\n"%(key,key_in,value_in)
print(dic_str)


