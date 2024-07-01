/* Assign Cookies
 * There is a parent, who has N children
 * each child has a greed_factor, (an array which stores the greed factors)
 * also the parent has M cookies, each size of known to the parent 
 */

import java.util.Arrays;

public class AssignCookies {

    public static void main(String[] args) {
        int[] cookies = { 4, 2, 1, 2, 1, 3 }; // cookies
        int[] children = { 1, 5, 3, 3, 4 }; // greed factor of children

        // sorting the arrays
        Arrays.sort(cookies);
        Arrays.sort(children);

        int n = children.length; // number of children
        int m = cookies.length; // number of cookies

        int child = 0;
        int cookie = 0;

        while (cookie < m) // until the cookies end
        {
            /*
            *if the size of a cookie is greater than or equal to the greed factor
            *only then assign the cookie to the child
            */
            if (children[child] <= cookies[cookie]) {
                child++;
                cookie++;
            } 
            else // else move on to the next cookie
            {
                cookie++;
            }
        }

        System.out.println(child + " children got the cookies");
    }
}