1. หมุนซ้ายเดี่ยว (Single Left Rotation)
   - ใช้เมื่อต้นไม้หนักทางด้านขวา ทำให้ต้นไม้ไม่สมดุล (Balance Factor < -1)
   - หมุนโหนดทางขวาขึ้นมาเป็นรากของ sub-tree และเลื่อนโหนดเดิมไปทางซ้าย
2. หมุนขวาเดี่ยว (Single Right Rotation)
   - ใช้เมื่อต้นไม้หนักทางด้านซ้าย (Balance Factor > 1)
   - หมุนโหนดทางซ้ายขึ้นมาเป็นรากของ sub-tree และเลื่อนโหนดเดิมไปทางขวา
3. หมุนซ้าย-ขวา (Left-Right Rotation)
   - ใช้เมื่อต้นไม้หนักทางซ้ายของลูกโหนดซ้าย (สองระดับ)
   - ทำการหมุนซ้ายที่โหนดลูกทางซ้ายก่อน จากนั้นทำการหมุนขวาที่โหนดราก
4. หมุนขวา-ซ้าย (Right-Left Rotation)
   - ใช้เมื่อต้นไม้หนักทางขวาของลูกโหนดขวา (สองระดับ)
   - ทำการหมุนขวาที่โหนดลูกทางขวาก่อน จากนั้นทำการหมุนซ้ายที่โหนดราก

### ตัวอย่างการหมุน:

การหมุน AVL Tree แต่ละแบบมีจุดประสงค์เพื่อทำให้ต้นไม้สมดุลเมื่อเกิดความไม่สมดุลในโครงสร้างของต้นไม้ โดยการหมุนสามารถแบ่งออกได้เป็น 4 แบบ ดังนี้:

### 1. หมุนซ้ายเดี่ยว (Single Left Rotation - RR Case)
สถานการณ์ที่ต้องใช้การหมุนซ้ายเดี่ยวคือ เมื่อต้นไม้มีการแทรกโหนดในฝั่งขวาต่อเนื่องกัน เช่น:
```
  10
    \
     20
       \
        30
```
ในกรณีนี้ โหนด 20 จะถูกหมุนขึ้นมาเป็นราก และโหนด 10 จะกลายเป็นโหนดลูกทางซ้าย:
```
   20
  /  \
 10   30
```

### 2. หมุนขวาเดี่ยว (Single Right Rotation - LL Case)
สถานการณ์ที่ต้องใช้การหมุนขวาเดี่ยวคือ เมื่อต้นไม้มีการแทรกโหนดในฝั่งซ้ายต่อเนื่องกัน เช่น:
```
    30
   /
  20
 /
10
```
ในกรณีนี้ โหนด 20 จะถูกหมุนขึ้นมาเป็นราก และโหนด 30 จะกลายเป็นโหนดลูกทางขวา:
```
   20
  /  \
 10   30
```

### 3. หมุนซ้าย-ขวา (Left-Right Rotation - LR Case)
สถานการณ์ที่ต้องใช้การหมุนซ้าย-ขวาคือ เมื่อต้นไม้มีการแทรกโหนดในฝั่งซ้าย-ขวา เช่น:
```
    30
   /
  10
   \
   20
```
ขั้นตอนการหมุนซ้าย-ขวาจะเป็นดังนี้:
1. หมุนซ้ายที่โหนด 10: โหนด 20 จะขึ้นมาแทนที่โหนด 10
2. หมุนขวาที่โหนด 30: โหนด 20 จะขึ้นมาแทนที่โหนด 30

ผลลัพธ์หลังจากการหมุนซ้าย-ขวา:
```
   20
  /  \
 10   30
```

### 4. หมุนขวา-ซ้าย (Right-Left Rotation - RL Case)
สถานการณ์ที่ต้องใช้การหมุนขวา-ซ้ายคือ เมื่อต้นไม้มีการแทรกโหนดในฝั่งขวา-ซ้าย เช่น:
```
    30
      \
      40
     /
    35
```
ขั้นตอนการหมุนขวา-ซ้ายจะเป็นดังนี้:
1. หมุนขวาที่โหนด 40: โหนด 35 จะขึ้นมาแทนที่โหนด 40
2. หมุนซ้ายที่โหนด 30: โหนด 35 จะขึ้นมาแทนที่โหนด 30

ผลลัพธ์หลังจากการหมุนขวา-ซ้าย:
```
   35
  /  \
 30   40
```

การหมุนเหล่านี้ช่วยให้โครงสร้างของ AVL Tree คงความสมดุลได้ตลอดเวลาหลังจากการแทรกหรือการลบโหนด