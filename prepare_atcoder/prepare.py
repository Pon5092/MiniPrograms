import os
import sys

configfile = '.\\config'
config =open(configfile,'r', encoding="utf-8")
for line in config.readlines():
    if(line.startswith("templates:")):
        templates = line.lstrip("templates:")
        templates =templates.replace('\n','')
    elif(line.startswith("to:")):
        to = line.lstrip("to:")
        to = to.replace('\n','')
    elif(line.startswith("type:")):
        typ = line.lstrip("type:")
        typ = typ.replace('\n','')
config.close()
print("現在の設定は")
print("コンテスト種類：" +typ)
print("出力ファイルディレクトリ："+to)
print("テンプレートファイル："+templates)
print("です")
numbers = input("番号を入力してください：")
locate = to + typ + " " + numbers
try:
    os.mkdir(locate)
except FileExistsError as e:
    print("もうある")
    o =input("それでもやりますか？？")
    if(o == 'y'):
        print("OK")
    if(o == 'n'):
        print("了解しました．終了します")
        sys.exit()
basefile = open(templates,mode ='r',encoding="utf-8")
for i in range(65,72):
    locatenow= locate + "\\" +chr(i) +".cpp"
    basefile = open(templates,mode ='r',encoding="utf-8")
    locatefile =open(locatenow,mode ='w', encoding="utf-8")
    for line in basefile.readlines():
        locatefile.write(line)
    locatefile.close()
    basefile.close()