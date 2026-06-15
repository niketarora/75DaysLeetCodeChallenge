class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop as long as there are characters to process or a carry remains
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to integer
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to integer
                j--;
            }

            // The bit to append is sum % 2 (either '0' or '1')
            result += to_string(sum % 2);

            // Calculate the new carry (either 0 or 1)
            carry = sum / 2;
        }

        // The result was built backwards, so reverse it before returning
        reverse(result.begin(), result.end());
        return result;
    }
};
