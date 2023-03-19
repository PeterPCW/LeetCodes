class BrowserHistory {
    private List<String> history;
    private int currentIndex;
    public BrowserHistory(String homepage) {
        history = new ArrayList<>(); // Initialize the history when the homepage opens
        history.add(homepage); // Add the homepage to the history
        currentIndex = 0; // Initialize the history index
    }
    public void visit(String url) {
        history.subList(currentIndex + 1, history.size()).clear(); // Clear the history from the current position forward
        history.add(url); // Add the current page to the history
        currentIndex++; // Increment the index to point to the new page
    }
    public String back(int steps) {
        currentIndex = Math.max(0, currentIndex - steps); // Set the current index back by however many steps were undone, but don't let it go negative
        return history.get(currentIndex); // Get the correct url for that number of steps backward
    } 
    public String forward(int steps) {
        currentIndex = Math.min(history.size() - 1, currentIndex + steps); // Set the current index forward by the number of steps, but don't exceed the size of the history
        return history.get(currentIndex); // Get the current url for that number of steps forward
    }
}
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */

// Source: https://leetcode.com/problems/design-browser-history/ 

/*
Explanation:
The browser history is stored as a list of string urls, with a parallel pointer storing the index in the history for the current page.
Initializing the browser history object creates the history list and populates the homepage as the first page.
When you visit a new page it clears the forward history and sets the new page as the latest page.
When you go back into the history it modifies the pointer to find the right page and returns the url, making sure to not go beyond the available pages.
Going forward works the same way, adjusting the index but staying within the history bounds and returning the url to show.
*/