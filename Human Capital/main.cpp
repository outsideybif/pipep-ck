#include "includes.h"

int main() {
	printf("Start boost in human capital project\n");

	HumanCapitalStrategy strategy = HumanCapitalStrategy(581, 0.197, 0.225, 0.158, 0.182, 0.212);
	
	std::vector<HumanCapitalAction*>* actions = new std::vector<HumanCapitalAction*>();
	actions->push_back(new HumanCapitalAction(1, 1, 0, 0, 0, 0));
	actions->push_back(new HumanCapitalAction(1, 0, 1, 0, 0, 0));
	actions->push_back(new HumanCapitalAction(1, 0, 0, 1, 0, 0));
	actions->push_back(new HumanCapitalAction(1, 0, 0, 0, 1, 0));
	actions->push_back(new HumanCapitalAction(1, 0, 0, 0, 0, 1));

	std::map<int, HumanCapitalState*> states = std::map<int, HumanCapitalState*>();

	size_t interval_for_values = 15;
	size_t count_of_unique_string_id = 0;
	std::stringstream string_of_index;
	std::stringstream index_of_first_level;
	std::stringstream index_of_second_level;
	std::stringstream index_of_third_level;
	std::stringstream index_of_fourth_level;
	
	
		

	//for (size_t i1 = 0; i1 < interval_for_values; i1++)
	//{
	//	index_of_first_level.str("");
	//	index_of_first_level << i1 << ",";

	//	for (size_t i2 = 0; i2 < interval_for_values; i2++)
	//	{
	//		index_of_second_level.str("");
	//		index_of_second_level << index_of_first_level.str() << i2 << ",";

	//		for (size_t i3 = 0; i3 < interval_for_values; i3++)
	//		{
	//			index_of_third_level.str("");
	//			index_of_third_level << index_of_second_level.str() << i3 << ",";

	//			for (size_t i4 = 0; i4 < interval_for_values; i4++)
	//			{
	//				index_of_fourth_level.str("");
	//				index_of_fourth_level << index_of_third_level.str() << i4 << ",";

	//				for (size_t i5 = 0; i5 < interval_for_values; i5++)
	//				{
	//					string_of_index.str("");
	//					string_of_index << index_of_fourth_level.str() << i5;

	//					std::string unique_string_id = string_of_index.str();
	//					//std::cout << unique_string_id << "\n";
	//					states[unique_string_id] = new HumanCapitalState(&strategy, actions);
	//					count_of_unique_string_id++;
	//				}
	//			}
	//		}
	//	}
	//}
	for (double i = 0; i < 35; i+=0.0001)
	{
		states[i] = new HumanCapitalState(&strategy, actions);
	}
	
	
	std::cout << sizeof(strategy) << "\n";
	std::cout << sizeof(actions) << "\n";
	std::cout << sizeof(states) << "\n";


	std::cout << sizeof(HumanCapitalState(&strategy, actions)) << "\n";
	std::cout << string_of_index.str() << "\n";
	std::cout << count_of_unique_string_id << "\n";
	printf("States created\n");

	HumanCapitalLooper* looper = new HumanCapitalLooper(&strategy, 25,
		actions, states);

	std::string input;
	

	/*while (true)
	{
		std::cin >> input;
		
	}*/

	for (unsigned long long int i = 0; i < 744073709551615; i++)
	{
		looper->NextStep();
	}

	/*strategy.Reset();
	strategy.AddCultural(100);
	strategy.AddEducation(100);
	strategy.AddHealth(100);
	strategy.AddInformation(100);
	strategy.AddSalary(100);
	strategy.PrintData(0, 0, 0);
	std::cin >> input;

	strategy.Reset();
	strategy.AddCultural(100);
	strategy.AddEducation(100);
	strategy.AddInformation(100);
	strategy.AddSalary(100);
	strategy.PrintData(0, 0, 0);
	std::cin >> input;
	*/

	/*strategy.Reset();
	strategy.AddHealth(1039);
	strategy.PrintData(0, 0, 0, 0);
	std::cin >> input;*/

	

	return 0;
}