const fs = require('fs');
const readlineSync = require('readline-sync');

const N = 21;
// const N = 1001;
// const N = 5001;
// const N = 10001;
// const N = 50001;
class HashTable {
  store = [];

  hash1(key) {
    return key % N;
  }

  hash2(key) {
    return key + 1;
  }

  add(key, value) {
    let adr = this.hash1(key);

    if (this.store[adr] != undefined) {
      while (this.store[adr] != undefined) {
        adr = this.hash2(adr);
      }
    }
    value.adr = adr;
    this.store[adr] = value;
  }

  readFromFile(fileName) {
    let data = fs.readFileSync(fileName);
    let arr = data.toString();
    arr = JSON.parse(arr);
    for (let i = 0; i < arr.length; i++) {
      this.add(arr[i].avarageMark, arr[i]);
    }
  }

  printAll() {
    console.log(this.store);
  }

  search(key) {
    let adr = this.hash1(key);

    if (this.store[adr] == undefined) {
      return 'Cell of HastTable is empty';
    } else if (this.store[adr].avarageMark == key) {
      return this.store[adr];
    } else {
      let a1 = this.hash1(adr + 1);

      while ((this.store[a1] == undefined || this.store[a1].avarageMark != key) && a1 != adr) {
        a1++;
        if (this.store[a1] == undefined) {
          return 'No such key in HashTable';
        }
      }

      return this.store[a1];
    }
  }
}

const hash = new HashTable();
hash.readFromFile('input20.json');
// hash.readFromFile('input1000.json');
// hash.readFromFile('input5000.json');
// hash.readFromFile('input10000.json');
// hash.readFromFile('input50000.json');
hash.printAll();

let key = 1;
while (key != 0) {
  key = readlineSync.question('Enter searched key: ');
  console.log(hash.search(key));
}
