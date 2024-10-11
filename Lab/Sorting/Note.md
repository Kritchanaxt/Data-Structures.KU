
## Sorting
1. Bubble Sort:
- ทำงานโดยเปรียบเทียบค่าที่อยู่ติดกันและสลับตำแหน่งถ้าค่าตัวแรกมากกว่าค่าตัวหลัง ทำซ้ำจนกว่าลิสต์จะเรียงลำดับสมบูรณ์

### Concept
- เหมือนเรียงแถวตามระดับความสูง เช่น คนที่สูงสลับกับคนที่เตี้ยกว่า

1. Merge Sort:
- เป็นการจัดเรียงแบบแยกและรวม (Divide and Conquer) โดยแยกข้อมูลเป็นครึ่งหนึ่งจนมีขนาดเล็กสุด แล้วค่อย ๆ รวมกลับมาโดยการจัดเรียงในแต่ละขั้นตอน

### Concept
- คือ การเอา array มาต่อกัน โดยการหาค่าตรงกลางก่อน Mid = (BEG + END) / 2 เพื่อหาค่า MID 
- และ ให้  I อยู่ฝั่ง BEG, J อยู่ฝั่ง END , Array 2 = temp 
- โดยเงื่อนไข ให้ทำการเปรียบเทียบค่า โดยการนำค่าที่น้อยกว่า ไปสำเนาที่ Array 2 และไล่ไปที่ละ Index เช่น MID = 3 
- Array1[1,2,3,4,5,6] สำเนาค่าน้อยทีละตัว -> Array2[1,2,...,6]

1. Quick Sort:
- เป็นการจัดเรียงที่เลือก "ตัวชี้" (pivot) แล้วแยกข้อมูลเป็นสองส่วนคือค่าที่น้อยกว่าหรือมากกว่า pivot หลังจากนั้นจะจัดเรียงแต่ละส่วนแยกกัน

- left = < น้อยกว่า
- right = > มากกว่า
- log = Located อยู่กับที่ 

ARRAY [25,10,18,27,36,45]

### Concept 
- ให้ left อยู่ฝั่งซ้ายสุดก็คือ 25 , right อยู่ฝั่งขวาสุดก็คือ 45
- โดยเงื่อนไข คือ เปรียบเทียบค่า ถ้ามีค่ามากให้อยู่ฝั่งขวา ถ้าค่าน้อยอยู่ฝั่งซ้าย
- โดยให้โยน loc ไปพร้อมกับตัวที่สลับ
- จังหวะสลับโยน loc มาด้วย เช่น loc, left -> loc, right

### Things to do
1. ต้องเปรียบเทียบเพื่อหาค่า mid 
2. จะหาค่า mid โดยทำการเปรียบเทียบเรื่อยๆจนกว่า left, right, loc จะตรงกัน
2. ระเบิด array ออกมาเป็น 2 ก้อน 
3. เปรียบเทียบ ทีละก้อน หาก ยังไม่ถูกต้อง ก็ระเบิดอีกครั้ง และทำเหมือนเดิม 
เช่น 18,10,25 -> 18,10 = 10,18
4. หาผลลัพธ์จากแต่ละรอบ 

รอบ 1 = 25,10,18,27,36,45
รอบ 2 = 36,45
รอบ 3 = 18,10,25
รอบ 4 = 10, 18
Result = 10,18,25,27,36,45
