cnt = 0

for i in range(12):
    for j in range(5):
        cnt += 1
        # PieceDisplay::Label_Map[0][0] = ui->label_1;
        print(f'Label_Map[{i}][{j}] = ui->label_{cnt};')
        print(f'Label_Map[{i}][{j}]->row = {i}, Label_Map[{i}][{j}]->col = {j};')
