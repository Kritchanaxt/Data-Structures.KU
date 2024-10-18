
### Big O Notation 
- เป็นวิธีการใช้เพื่อวัดประสิทธิภาพของอัลกอริทึมในแง่ของเวลาในการทำงาน (Time Complexity) หรือหน่วยความจำที่ใช้ (Space Complexity) โดยจะบอกถึงการเติบโตของอัลกอริทึมเมื่อขนาดของข้อมูล (n) เพิ่มขึ้น ซึ่งจะช่วยให้สามารถประเมินได้ว่าอัลกอริทึมใดมีประสิทธิภาพมากกว่ากัน

#### ประเภทของ Big O Notation
1. O(1) - Constant Time: เวลาในการทำงานไม่เปลี่ยนแปลงตามขนาดของข้อมูล เช่น การเข้าถึงสมาชิกในอาร์เรย์โดยใช้ดัชนี

int getFirstElement(int arr[]) {
    return arr[0]; // O(1)
}

2. O(n) - Linear Time: เวลาในการทำงานเพิ่มขึ้นตามขนาดของข้อมูล เช่น การวนลูปผ่านสมาชิกในอาร์เรย์ทั้งหมด

void printAllElements(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // O(n)
    }
}

3. O(n) - Linear Time: เวลาในการทำงานเพิ่มขึ้นตามขนาดของข้อมูล เช่น การวนลูปผ่านสมาชิกในอาร์เรย์ทั้งหมด

void printAllPairs(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d, %d) ", arr[i], arr[j]); // O(n^2)
        }
    }
}

4. O(log n) - Logarithmic Time: เวลาในการทำงานเพิ่มขึ้นตามลอการิทึมของขนาดข้อมูล เช่น การค้นหาแบบ Binary Search

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // O(log n)
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Target not found
}

5. O(n log n) - Linearithmic Time: เวลาในการทำงานเพิ่มขึ้นเป็นเส้นตรงคูณกับลอการิทึมของขนาดข้อมูล เช่น การเรียงลำดับแบบ Merge Sort หรือ Quick Sort

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid); // O(n log n)
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

6. O(2^n) - Exponential Time: เวลาในการทำงานเพิ่มขึ้นเป็นสองเท่าของขนาดข้อมูล เช่น อัลกอริทึมที่เกี่ยวกับการคำนวณฟีโบนัชชี่แบบเรียกซ้ำ

int fibonacci(int n) {
    if (n <= 1) {
        return n; // O(2^n)
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

7. O(n!) - Factorial Time: เวลาในการทำงานเพิ่มขึ้นตามแฟกทอเรียลของขนาดข้อมูล เช่น การจัดเรียงแบบ Permutation

void permute(char* str, int left, int right) {
    if (left == right) {
        printf("%s\n", str); // O(n!)
    } else {
        for (int i = left; i <= right; i++) {
            swap((str + left), (str + i));
            permute(str, left + 1, right);
            swap((str + left), (str + i)); // backtrack
        }
    }
}

#### สรุป
- Big O Notation ช่วยบอกถึงความซับซ้อนของอัลกอริทึมโดยไม่สนใจรายละเอียดของฮาร์ดแวร์หรือซอฟต์แวร์
- เลขยกกำลังสูงและแฟกทอเรียลมีการเติบโตที่รวดเร็วที่สุด และอัลกอริทึมที่ซับซ้อนควรหลีกเลี่ยง