function countSort(arr) {
	let output = new Array;
	let count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];

	for (let i = 0; i < arr.length; i++)
		count[arr[i]]++;

	for (let i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for(let i = arr.length - 1; i >= 0; i--) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	return output;
}

var arr = [8, 9, 6, 0, 1, 8, 6, 5, 4, 2, 9, 8, 0, 1, 3];
console.log(countSort(arr));
