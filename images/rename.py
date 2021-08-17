from pypinyin import Style, pinyin
import glob
import os

for file in glob.glob('*'):
    if '蓝' in file or '红' in file:
        filename = file.split('.')[0]
        pre = pinyin(filename.split('_')[0], style=Style.NORMAL)
        pre_str = ''
        for c in pre:
            pre_str += c[0]
        pos = 'blue' if '蓝' in file else 'red'
        newname = f'{pre_str}_{pos}.png'
        print(file, newname)
        os.rename(file, newname)
