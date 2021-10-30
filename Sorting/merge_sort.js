function mergeSort(arr){
	if(arr.length < 2) return arr;

	const mid_idx = Math.floor(arr.length / 2);
	const leftArr = arr.slice(0, mid_idx);
	const rightArr = arr.slice(mid_idx, arr.length - 1);

	return merge(mergeSort(leftArr), mergeSort(rightArr));
}

function merge(leftArr, rightArr){
	let resultArr = [];
	let leftIndex = 0;
	let rightIndex = 0;

	while(leftIndex < leftArr.length && rightIndex < rightArr.length){
		if(leftArr[leftIndex] < rightArr[rightIndex]){
			resultArr.push(leftArr[leftIndex]);
			leftIndex += 1;
		} else {
			resultArr.push(rightArr[rightIndex]);
			rightIndex += 1;
		}
	}
	return resultArr.concat(leftArr.slice(leftIndex)).concat(rightArr.slice(rightIndex));
}

let arr = [3, 27, 69, 42, 91, 21];
console.log(mergeSort(arr));
