let arr = [13,19,9,5,12,8,7,4,11,2,6,21,35,8,13,30,4,1,20,10,23,27,2,5,6,37,12,24,26,3,8,9,10,54,56,10,32];

function select(list, left, right, n) {
  while(true){
    if(left == right) return left;
    let pivotIndex = pivot(list, left, right);
    pivotIndex = partition(list, left, right, pivotIndex);
    if(n == pivotIndex) return n;
    else if(n < pivotIndex) right = pivotIndex - 1;
    else left = pivotIndex + 1;
  }
}

function partition(list, left, right, pivotIndex) {
  let pivotValue = list[pivotIndex];
  [ list[pivotIndex], list[right] ] = [ list[right], list[pivotIndex] ];
  let storeIndex = left;
  for(let i = left; i < right; ++i) {
    if(list[i] < pivotValue) {
      [ list[storeIndex], list[i] ] = [ list[i], list[storeIndex] ];
      storeIndex++;
    }
  }
  [ list[storeIndex], list[right] ] = [ list[right], list[storeIndex] ];
  return storeIndex;
}

function pivot(list, left, right) {
  if(right - left < 5) return partition5(list, left, right);
  for(let i = left; i <= right; i += 5) {
    let subRight = i + 4;
    if(subRight > right) subRight = right;
    let median5 = partition5(list, i, subRight);
    [ list[median5], list[left + Math.floor((i - left)/5)] ] = [ list[left + Math.floor((i - left)/5)], list[median5] ];
  }
  return select(list, left, left + Math.floor((right - left) / 5), left + Math.floor((right - left) / 10));
}

function partition5(list, left, right) {

  let i, j, tmp;
  for(i = left + 1; i <= right; ++i){
    let tmp = list[i];
    for(j = i; j > left && list[j-1] > tmp; j--)
      list[j] = list[j-1];
    list[j] = tmp;
  }
  
  return left + Math.floor((right - left) / 2);
}

let p = pivot(arr,0,arr.length-1);
console.log("selected pivot = " + arr[p]);
arr.sort((a, b) => a - b);
console.log("Median = " + arr[Math.floor(arr.length/2)]);
