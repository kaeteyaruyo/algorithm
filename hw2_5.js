let arr = [13,19,9,5,12,8,7,4,11,2,6,21,35,8,13,30,4,1,20,10,23,27,2,5,6,37,12,24,26,3,8,9,10,54,56,10,32];

// pivot function is used to choose a pivot from a bunch of medians,
// by dividing number into groups of 5, and pick median of each,
// then recursively divide these medians, until we got the median of medians
function pivot(list, left, right) {

  // if list range is less than 5, just return the median
  if(right - left < 5) return partition5(list, left, right);

  // else, divide list into gruops of 5 and pick median of each,
  // and put them together into the head of whole list
  for(let i = left; i <= right; i += 5) {
    let subRight = i + 4;
    if(subRight > right) subRight = right;
    let median5 = partition5(list, i, subRight);
    [ list[median5], list[left + Math.floor((i - left)/5)] ] = [ list[left + Math.floor((i - left)/5)], list[median5] ];
  }

  // and then get median of medians as pivot
  return select(list, left, left + Math.floor((right - left) / 5), left + Math.floor((right - left) / 10));
}

// select function is used to get the pivot,
// and use this pivot to divide the list from caller into 2 group:
// bigger than pivot one and small than pivot one.
// The argumemt n is the center index of the list from the caller.
// After partition, if the pivot is just at the center, than it is the median.
// else we recursively find into the longer group and finally got the medain.
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

// partition function is like the partition function in the quick sort,
// is used to divide the list from caller into 2 group:
// bigger than pivot one and smaller than pivot one,
// and put pivot to the center.
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

// partition5 is used to pick the median from at most 5 number
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

// To show that the selected pivot is roughly the same as median
let p = pivot(arr,0,arr.length-1);
console.log("selected pivot = " + arr[p]);
arr.sort((a, b) => a - b);
console.log("Median = " + arr[Math.floor(arr.length/2)]);
