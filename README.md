# Data-Structure--Buying-Selling-Shares-of-Stocks.

Buying/Selling Shares of Stocks.
Buying and selling shares of stocks of listed companies is a typical task to do among investors. Of course, this would result in a capital gain (or loss) when the shares are sold. This is computed as the difference between the shares’ selling price and the price was originally paid to buy it.
When an investor has a single share of stock, the process is easy. However, when (s)he sells multiple shares of stocks, bought over a period of time and possibly with different prices, the first step is to identify which shares of stocks are to be sold. There are two accounting principles that are followed depends on the market of stocks: the shares bought last to be sold first, and the other is to sell the shares that stayed the longest.
You are required to implement a program to calculate the possible capital gain/loss using these two protocols. This would facilitate the process for investors to know which market to go for and invest their money in.
As an example, suppose investor A bought the following shares as follows:
130 shares at $30 each on 1 March 20 shares at $35 each on 5 March 50 shares at $40 each of 10 March
and he sold:
100 shares at $35 each on 15 March
Applying the first principle (i.e., FIFO) means that the 100 shares would be sold from the 130 shares that he bought on 1 March. Thus, the capital gain would be 100 * $5 = $500, where $5 is the difference in price between the original price when bought and when sold. On the other hand, by applying the second principle (i.e., LIFO), that means the capital gain is 50 * (-$5) + 20 * $0 + 30 * $5 = -250 + 150 = -$100.
Your program should include the following tasks:
1. Read stocks’ transaction
2. Buy shares
3. Sell shares
a. Sell old shares first
b. Sell new shares first
4. Total capital gain/loss
5. Update currently held shares
6. Exit
Option 1: this command will read a file that, if exists, will contain the currently held shares of the investor: the number of shares, their buying dates, and the price of a single shares at the purchase time, and the name of the company the shares belong to. The name of the file is (shares.txt) and the input file format is specified as follows:
Number of shares; Price per share; Company; Date
Option 2: this option will allow the user to buy new shares by specifying the number of shares to buy, at what price, and the name of the company the shares belong to. The shares entered should be updated and added to the shares currently held. When the user enters the required information, a confirmation message should appear and then the main menu should be displayed. You should also enter the name of the company you want to buy the shares from.
Option 3: this command will allow the user to sell shares of stocks using any of the two principles. Once the information (i.e., number of shares to sell, at what price, and the name of the company the shares belong to) has been entered and confirmed by a proper message, the list of currently held shares should be updated, and the capital gain/loss should be updated.
Once the shares are sold, you should display the details of how the shares where profit/loss is encountered. Of course, you have to specify the company you are selling their shares and apply the logic only to the its shares.
Option 4: this command will print the total capital gain/loss from all transactions that took place.
Option 5: to store the currently held shares back to the transactions file.
Options 6: exit the program (after applying option 5).
