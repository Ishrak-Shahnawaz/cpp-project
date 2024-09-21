#include<iostream>
using namespace std;

struct Order
{
    string cus_name;
    string cake_name;
    int quantity;
    int bill;
};


struct Cake
{
    string cake_name;
    int stock;
    int price;
};


int main()
{
//-----------------------------------------------------------------------------------------------------------------
    Cake cake[5];
    cake[0].cake_name = "red_velvet";
    cake[1].cake_name = "vanilla";
    cake[2].cake_name = "chocolate";
    cake[3].cake_name = "rainbow";
    cake[4].cake_name = "lemon";

    cake[0].price = 1000;
    cake[1].price = 500;
    cake[2].price = 600;
    cake[3].price = 800;
    cake[4].price = 800;

    cake[0].stock = 10;
    cake[1].stock = 5;
    cake[2].stock = 2;
    cake[3].stock = 6;
    cake[4].stock = 8;
//-----------------------------------------------------------------------------------------------------------------

    Order order[100];
    int count=0;

    for(int i=0; i<1; i--)
    {
        int opp;
        cout<<"1. Add Order."<<endl;
        cout<<"2. Order Info."<<endl;
        cout<<"3. Add Inventory."<<endl;
        cout<<"4. Change Price."<<endl;
        cout<<"5. Inventory Info."<<endl;
        cout<<"6. Profit Info."<<endl;
        cout<<"Press - ";
        cin>>opp;

//-----------------------------------------------------------------------------------------------------------------
        if(opp==1)
        {
            cout<<"---------------------------"<<endl;

            string cus_name_op;
            cout<<"Customer Name - ";
            cin>>cus_name_op;

            string cake_name_op;
            cout<<"Cake Name - ";
            cin>>cake_name_op;

            bool flag=false;
            for(int i=0; i<5; i++)
            {
                if(cake[i].cake_name==cake_name_op)
                {
                    int quantity_op;
                    cout<<"Quantity - ";
                    cin>>quantity_op;

                    if(quantity_op<=cake[i].stock)
                    {
                        int bill_op = cake[i].price*quantity_op;
                        cout<<"Bill - "<<bill_op<<endl;

                        cout<<"Order Succesful"<<endl;

                        cout<<"---------------------------"<<endl;

                        order[count].cus_name = cus_name_op;
                        order[count].cake_name = cake_name_op;
                        order[count].quantity = quantity_op;
                        order[count].bill = bill_op;

                        cake[i].stock = cake[i].stock - quantity_op;

                        count++;

                        cout<<endl;
                        cout<<endl;

                    }

                    else
                    {
                        cout<<"No Enough Cake!"<<endl;
                        cout<<"Order Cancel"<<endl;
                        cout<<"---------------------------"<<endl;

                        cout<<endl;
                        cout<<endl;
                    }

                    flag = true;
                    break;


                }

                else
                {
                    flag=false;
                }

            }

            if(flag==false)
            {
                cout<<"Wrong Cake Name!"<<endl;
                cout<<"---------------------------"<<endl;

                cout<<endl;
                cout<<endl;
            }


        }

//-----------------------------------------------------------------------------------------------------------------
        else if(opp==2)
        {
            cout<<"---------------------------"<<endl;
            cout<<"Order Info"<<endl;
            cout<<"TOTAL ORDER - "<<count<<endl;
            for(int i=0; i<count; i++)
            {
                cout<<"---------------------------"<<endl;

                cout<<"Order: "<<i+1<<endl;
                cout<<"Customer Name: "<<order[i].cus_name<<endl;
                cout<<"Cake Name: "<<order[i].cake_name<<endl;
                cout<<"Quantity: "<<order[i].quantity<<endl;
                cout<<"Bill: "<<order[i].bill<<endl;

            }
            cout<<"---------------------------"<<endl;
            cout<<endl;
            cout<<endl;

        }

//-----------------------------------------------------------------------------------------------------------------
        else if(opp==3)
        {
            cout<<"---------------------------"<<endl;

            string cake_name_op;
            cout<<"Cake Name - ";
            cin>>cake_name_op;

            bool add=false;

            for(int i=0; i<5; i++)
            {
                if(cake_name_op==cake[i].cake_name)
                {
                    int no;
                    cout<<"No. of Cake - ";
                    cin>>no;

                    cake[i].stock = cake[i].stock + no;

                    cout<<"Cake Added Successfully"<<endl;
                    cout<<"---------------------------"<<endl;

                    cout<<endl;
                    cout<<endl;

                    add=false;
                    break;

                }

                else
                {
                    add=true;
                }

            }

            if(add==true)
            {
                cout<<"Wrong Cake Name!"<<endl;
                cout<<"---------------------------"<<endl;

                cout<<endl;
                cout<<endl;

            }


        }

//-----------------------------------------------------------------------------------------------------------------
        else if(opp==4)
        {
            cout<<"---------------------------"<<endl;

            string cake_name_op;
            cout<<"Cake Name - ";
            cin>>cake_name_op;

            bool pri=false;

            for(int i=0; i<5; i++)
            {
                if(cake_name_op==cake[i].cake_name)
                {
                    int price_op;
                    cout<<"New Price - ";
                    cin>>price_op;

                    cake[i].price = price_op;

                    cout<<"Price Changed"<<endl;
                    cout<<"---------------------------"<<endl;

                    cout<<endl;
                    cout<<endl;

                    pri=false;
                    break;

                }

                else
                {
                    pri=true;
                }

            }

            if(pri==true)
            {
                cout<<"Wrong Cake Name!"<<endl;
                cout<<"Price Not Changed"<<endl;
                cout<<"---------------------------"<<endl;

                cout<<endl;
                cout<<endl;

            }



        }

//-----------------------------------------------------------------------------------------------------------------
        else if(opp==5)
        {
            cout<<"---------------------------"<<endl;
            cout<<"Inventory Info"<<endl;
            cout<<"---------------------------"<<endl;

            for(int i=0; i<5; i++)
            {
                cout<<"Cake Name: "<<cake[i].cake_name<<endl;
                cout<<"No. of Cake: "<<cake[i].stock<<endl;
                cout<<"Price: "<<cake[i].price<<endl;

                cout<<endl;

            }
            cout<<"---------------------------"<<endl;
            cout<<endl;
            cout<<endl;

        }

//-----------------------------------------------------------------------------------------------------------------
        else if(opp==6)
        {
            cout<<"---------------------------"<<endl;
            cout<<"Profit Info"<<endl;
            cout<<"---------------------------"<<endl;

            int p_money=0;
            for(int i=0; i<count; i++)
            {
                p_money = p_money + order[i].bill;
            }

            int i_money=0;
            for(int i=0; i<5; i++)
            {
                i_money = i_money + (cake[i].price*cake[i].stock);
            }

            cout<<"Inventory Price: "<<i_money<<endl;
            cout<<"Profit: "<<p_money<<endl;
            cout<<"---------------------------"<<endl;

            cout<<endl;
            cout<<endl;

        }

//-----------------------------------------------------------------------------------------------------------------
        else
        {
            cout<<"Try Again!"<<endl;
            cout<<endl;
            cout<<endl;
        }
//-----------------------------------------------------------------------------------------------------------------

    }




}
