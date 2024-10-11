
## Minimum Spanning Trees (MST)

Minimum Spanning Tree (MST) คือ กราฟต้นไม้ (Tree) ที่เป็นส่วนน้อยที่สุดของกราฟที่เชื่อมต่อกัน ซึ่งมีผลรวมของน้ำหนักเส้นเชื่อม (Edge Weight) ต่ำที่สุด โดย MST ต้องประกอบไปด้วย:
1. ไม่มีวงจร (Cycle)
2. เชื่อมต่อกันทุกจุด (Connected)
3. ใช้เส้นเชื่อม (Edges) ที่มีน้ำหนักรวมต่ำที่สุด
4. MST มีประโยชน์ในการแก้ปัญหาต่างๆ เช่นการออกแบบเครือข่ายที่มีค่าใช้จ่ายต่ำที่สุด

### Prim's Algorithm (อัลกอริทึมของพริม)
Prim's Algorithm ใช้สำหรับหาต้นไม้ที่ครอบคลุมทั้งหมด (Minimum Spanning Tree) โดยอัลกอริทึมนี้จะเริ่มต้นจากจุดยอด (Vertex) จุดหนึ่ง แล้วค่อยๆ ขยายไปยังจุดยอดข้างเคียงที่มีน้ำหนักเส้นเชื่อมต่ำที่สุดจนกว่าจะครอบคลุมทุกจุดยอดในกราฟ

***ขั้นตอน:***
1. เริ่มจากจุดยอดใดก็ได้ในกราฟ
2. เลือกเส้นเชื่อมที่มีน้ำหนักน้อยที่สุดจากจุดที่เยี่ยมชมแล้วไปยังจุดยอดที่ยังไม่ได้เยี่ยมชม
3. ทำซ้ำจนกระทั่งทุกจุดยอดถูกเยี่ยมชม


### Kruskal's Algorithm (อัลกอริทึมของครัสคาล)
Kruskal's Algorithm ใช้สำหรับหาต้นไม้ที่ครอบคลุมทั้งหมด (Minimum Spanning Tree) โดยการจัดลำดับเส้นเชื่อม (Edges) จากน้ำหนักน้อยที่สุดไปมากที่สุด และค่อยๆ เพิ่มเส้นเชื่อมที่ไม่มีวงจร (Cycle) จนกว่าจะสร้างต้นไม้ที่เชื่อมต่อทุกจุดยอด

***ขั้นตอน:***
1. จัดลำดับเส้นเชื่อมตามน้ำหนักจากน้อยไปมาก
2. เริ่มจากเส้นเชื่อมที่น้ำหนักน้อยที่สุด
3. เพิ่มเส้นเชื่อมตราบใดที่ไม่ทำให้เกิดวงจร
4. ทำซ้ำจนกระทั่งเชื่อมต่อครบทุกจุดยอด

### Dijkstra's Algorithm (อัลกอริทึมของไดจ์กสตรา)
Dijkstra's Algorithm ใช้สำหรับการหาทางที่สั้นที่สุดจากจุดต้นทางไปยังทุกจุดในกราฟที่มีน้ำหนักบวก (Positive Weights)

***ขั้นตอน:***
1. เริ่มจากจุดยอดต้นทาง
2. กำหนดระยะทางของจุดยอดต้นทางเป็น 0 และจุดยอดอื่นๆ เป็น ∞ (Infinity)
3. เลือกจุดยอดที่ยังไม่เยี่ยมชมและมีระยะทางน้อยที่สุด
4. ปรับปรุงระยะทางของจุดยอดข้างเคียงของจุดยอดนั้นๆ หากระยะทางสั้นกว่า
5. ทำซ้ำจนกระทั่งเยี่ยมชมครบทุกจุดยอด