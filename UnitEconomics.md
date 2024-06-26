# Unit Economics

## Revenues and costs per unit, to calculate cash flows over time and customer lifetime value (LTV)

### Per unit economics
| Item                                   | Amount | Type, Notes                                               |
|----------------------------------------|--------|-----------------------------------------------------------|
| Revenues                               |        |                                                           |
| One-time hardware sale                 | $200   | One time                                                  |
| Annual software subscription           | $100   | Recurring                                                 |
| Additional hardware (sensors and coolers) | $130   | One time                                                  |
| VR Headset sale                        | $300   | One time                                                  |
| Cost of Sales                          |        |                                                           |
| Sensors (average)                      | $30    | One time                                                  |
| Coolers                                | $100   | One time                                                  |
| Device                                 | $200   | One time                                                  |
| VR Headset                             | $300   | One time                                                  |
| Software                               | $100   | Recurring                                                 |

### Optional: Hide or show the column notes: show

### Revenues
| Description                                                          | Amount  | Type       |
|----------------------------------------------------------------------|---------|------------|
| Hardware unit sale (average revenue per unit)                        | $200    | One time   |
| Annual software subscription                                         | $100    | Recurring  |
| Additional hardware (sensors and coolers)                            | $130    | One time   |
| VR Headset sale (one-time revenue, not included in recurring)        | $300    | One time   |

### Cost of Sales
| Description                     | Percentage | Type       |
|---------------------------------|-------------|------------|
| Cost of hardware components     | 90%         | One time   |
| Cost of software (recurring)    | 10%         | Recurring  |

### Optional: Discounts
| Description                   | Amount | Notes                              |
|-------------------------------|--------|------------------------------------|
| Discounts for recurring       | $0     | Total, over billing period         |
| Discounts for transaction     | $0     | Total, first transaction only      |

### Churn and Growth, Recurring
| Description                                           | Amount | Notes                                               |
|-------------------------------------------------------|--------|-----------------------------------------------------|
| Recurring - Period for billing, # of months           | 12     | Defines the billing cycle, so that cash collection can be separate from revenues. By default, this equals the period for churn, but you can overwrite and change it |
| Recurring - Period for churn, growth, # months        | 12     | Define the length of a cycle for churn. Annual = 12, monthly = 1 |
| % Growth in Gross Margin per unit, linear annual growth | 30%   | Annual rate, linear growth                          |
| % Churn, every 12 months                              | 5%     | % that do not renew                                 |
| Average Customer Lifetime                             | 240    | # months                                            |

### Timing, One time
| Description                                          | Amount | Notes                              |
|------------------------------------------------------|--------|------------------------------------|
| Months after acquisition when one-time occurs        | 12     | Months; this will be zero for upfront, one-time fees, perhaps assume 12 for one-time fees that happen after 1 year |

### Churn and Growth, Transaction
| Description                                             | Amount | Notes                                              |
|---------------------------------------------------------|--------|----------------------------------------------------|
| Transaction - Period for churn, growth, # months        | 12     | Months                                             |
| % Growth in Gross Margin per unit, linear annual growth | 30%    | Annual rate, linear growth                         |
| % Churn, every period                                   | 5%     | % that do not repeat                               |
| Average # Repeat Transactions per year                  | 1.0    | Average lifetime one time purchases, before churn  |
| Average # of Lifetime Transactions                      | 20.0   | Calculated                                         |

### Discount Rate
| Description                  | Amount | Notes                           |
|------------------------------|--------|---------------------------------|
| Discount Rate                | 5.0%   | Optional, assume an annual rate. Used if you want to discount the future cash flows, using methodology from https://www.forentrepreneurs.com/ltv/ |
| K, Recurring                 | 0.95   | Optional, only used if using discount rate |
| K, Transaction               | 0.95   | Optional, only used if using discount rate |

### Acquisition and Retention Costs
| Description                                        | Amount  | Notes                          |
|----------------------------------------------------|---------|--------------------------------|
| Customer Acquisition Cost (CAC)                    | $120    | May need to adjust based on one time discounts, which costs to use from CAC forecast, and other business-specific issues |
| Cost of Retention and Expansion, Recurring         | $10     | For subscription renewals      |
| Cost of Repeat and Expansion, Transaction          | $120    | For repeat transactions        |

### LTV Analysis
| Description                   | Amount    | Notes                                                                                                      |
|-------------------------------|-----------|------------------------------------------------------------------------------------------------------------|
| LTV, Recurring                | $38       | Formula for LTV from https://www.forentrepreneurs.com/ltv/ to use discount rate (optional), and growth in average revenue (optional) |
| LTV, One-time                 | $(1,160)  | LTV = revenues less cost of sales for this one time cash flow assumed in the first month of forecast       |
| LTV, Transaction              | $(1,122)  | Formula for LTV from https://www.forentrepreneurs.com/ltv/ to use discount rate (optional), and growth in average revenue (optional) |
| LTV                           | $(1,122)  | Sum of all LTVs                                                                                           |
| LTV / CAC                     | $(9)      | LTV / CAC, to help measure profitability performance                                                       |
| CAC Payback                   | $(1.50)   | # of months to payback the customer acquisition costs, based on gross margin                               |

### Details for LTV calculations and Cash Flows per month +
Click on the "+" sign in the margin to see the detail behind the calculations

### Revenues, Cost of Sales, Gross Margin for LTV calculations
| Description                                | Amount       | Type       |
|--------------------------------------------|--------------|------------|
| Total Revenues, Recurring                  | $100         | Recurring  |
| Total Revenues, One-time                   | $400         | One time   |
| Total Revenues, Transaction                | $0           | Transaction|
| Total Cost of Sales, Recurring             | 90%          | Recurring  |
| Total Cost of Sales, One-time              | 90%          | One time   |
| Total Cost of Sales, Transaction           | 0%           | Transaction|
| Gross Margin, Recurring                    | $10          |            |
| Gross Margin, One-time                     | $40          |            |
| Gross Margin, Transaction                  | $0           |            |
| Gross Margin, Recurring, less cost of retention and expansion, recurring | $10 |            |
| Gross Margin, One-time, less retention     | $40          | Same as gross margin above    |
| Gross Margin, Transaction, less retention  | $(120)       | Includes costs of retention, expansion, and repeat in the gross margin calculation, reflecting CORE expenses as per https://www.forentrepreneurs.com/ltv/ |

## Per Month Cash Flows (continued)

| Description                              | Month from acquisition                        |
|------------------------------------------|----------------------------------------------|
|                                          | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 |
| Recurring (Timing of Renewal / Churn) #  | - | - | - | - | - | - | - | - | - | - | - | 1 | 1  |
| Repeat (Timing of Repeat / Churn) #      | - | - | - | - | - | - | - | - | - | - | - | 1 | 1  |
| Transactions (New and Repeat) #          | 1 | - | - | - | - | - | - | - | - | - | - | 1 | -  |
| Retention, Recurring %                   | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 95% | 95% |
| Retention, One-time %                    | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% |
| Retention, Transaction %                 | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 95% | 95% |

## Unit Economics, net of churn, per period

| Description                             | Amount per period | Notes                                                          |
|-----------------------------------------|-------------------|---------------------------------------------------------------|
| Revenues, Recurring                     | $100.0            |                                                               |
| Revenues, One-time                      | $400.0            |                                                               |
| Revenues, Transaction                   | $0.0              |                                                               |
| Cost of Sales, Recurring                | $90.0             |                                                               |
| Cost of Sales, One-time                 | $360.0            |                                                               |
| Cost of Sales, Transaction              | $0.0              |                                                               |
| Billings, net discounts, Recurring      | $1200.0           |                                                               |
| Billings, net discounts, One-time       | $400.0            |                                                               |
| Billings, net discounts, Transaction    | $0.0              |                                                               |
| Acquisition Costs                       | $120.0            |                                                               |
| Retention Costs                         | $10.0             |                                                               |
| Repeat Acquisition Costs                | $120.0            |                                                               |
| Billings, net of churn                  | $1542.0           |                                                               |
| Net Revenues, net of churn              | $495.0            |                                                               |
| Cost of Sales, net of churn             | $446.0            |                                                               |
| Gross Margin, net of churn, per period  | $49.0             |                                                               |
| Cumulative Gross Margin, net of churn   | $169.0            |                                                               |
| Net Gross Margin, net of churn, discounted | $47.0          |                                                               |
| Cumulative Gross Margin, net of churn, discounted | $164.0  |                                                               |

## LTV Analysis

| Description         | Amount  | Notes                                                                  |
|---------------------|---------|------------------------------------------------------------------------|
| LTV, Recurring      | $38     | Formula from [For Entrepreneurs](https://www.forentrepreneurs.com/ltv/) |
| LTV, One-time       | $(120)  |                                                                        |
| LTV                 | $(9)    | To help measure profitability performance                              |
| CAC Payback         | $(1.50) | Number of months to pay back the customer acquisition costs, based on gross margin |

## Revenues, Cost of Sales, Gross Margin for LTV calculations

| Description                                 | Amount        | Type       |
|---------------------------------------------|---------------|------------|
| Total Revenues, Recurring                   | $100          | Recurring  |
| Total Revenues, One-time                    | $400          | One time   |
| Total Revenues, Transaction                 | $0            | Transaction|
| Total Cost of Sales, Recurring              | 90%           | Recurring  |
| Total Cost of Sales, One-time               | 90%           | One time   |
| Total Cost of Sales, Transaction            | 0%            | Transaction|
| Gross Margin, Recurring                     | $10           |            |
| Gross Margin, One-time                      | $40           |            |
| Gross Margin, Transaction                   | $0            |            |
| Gross Margin, Recurring, less cost of retention and expansion, recurring | $10 | |
| Gross Margin, One-time, less retention      | $(120)        | Includes costs of retention, expansion, and repeat in the gross margin calculation, reflecting CORE expenses as per [For Entrepreneurs](https://www.forentrepreneurs.com/ltv/) |

## Cash Flow, per period and cumulative

| Description                       | Amount per period | Cumulative Amount | Notes          |
|-----------------------------------|-------------------|-------------------|----------------|
| Net Cash Flow, per period         | $990              |                   |                |
| Cumulative Net Cash Flow          |                   | $990              |                |
| Net Cash Flow, per period, discounted | $990          |                   |                |
| Cumulative Net Cash Flow, discounted |                | $990              |                |

## Timescale

| Description                              | Month from acquisition                        |
|------------------------------------------|----------------------------------------------|
|                                          | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 |
| Recurring (Timing of Billing Cycle) #    | - | - | - | - | - | - | - | - | - | - | - | 1 | 1  |
| Recurring (Timing of Renewal / Churn) #  | - | - | - | - | - | - | - | - | - | - | - | 1 | 1  |
| Repeat (Timing of Repeat / Churn) #      | - | - | - | - | - | - | - | - | - | - | - | 1 | 1  |
| Transactions (New and Repeat) #          | 1 | - | - | - | - | - | - | - | - | - | - | 1 | -  |
| Retention, Recurring %                   | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 95% | 95% |
| Retention, One-time %                    | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% |
| Retention, Transaction %                 | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 100% | 95% | 95% |

## Unit Economics, net of churn, per period

| Description                             | Amount per period | Notes                                                          |
|-----------------------------------------|-------------------|---------------------------------------------------------------|
| Revenues, net of churn, Recurring       | $100.0            |                                                               |
| Revenues, net of churn, One-time        | $400.0            |                                                               |
| Revenues, net of churn, Transaction     | $0.0              |                                                               |
| Cost of Sales, net of churn, Recurring  | $90.0             |                                                               |
| Cost of Sales, net of churn, One-time   | $360.0            |                                                               |
| Cost of Sales, net of churn, Transaction| $0.0              |                                                               |
| Billings, net discounts, Recurring      | $1200.0           |                                                               |
| Billings, net discounts, One-time       | $400.0            |                                                               |
| Billings, net discounts, Transaction    | $0.0              |                                                               |
| Acquisition Costs, net of churn         | $120.0            |                                                               |
| Retention Costs, net of churn           | $10.0             |                                                               |
