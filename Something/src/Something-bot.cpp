#include <iostream>
#include <aegis.hpp>

using json = nlohmann::json;
using string = std::string;

string read_token();
void set_bot_properties();

int main()
{
	set_bot_properties();
	return 0;
}

string read_token()
{
	json token_file;
	std::ifstream file_in("Data/Token.json");
	file_in >> token_file;

	return token_file["token"];
}

void set_bot_properties() 
{
	// Creates bot with log and token (read from Data/Token.json file)
	aegis::core bot(aegis::create_bot_t().log_level(spdlog::level::trace).token(read_token()));
	// Writes a line in the log file "bot.log"
	AEGIS_TRACE(bot.log, "Bot object was created");
	// Tells the websocket to display debug mesages
	bot.wsdbg = true;

	bot.set_on_message_create([&](aegis::gateway::events::message_create obj)
		{
			// TODO have input lowercased
			string content{ obj.msg.get_content() };
			auto& _channel = obj.msg.get_channel();
			if (content == "~cunt")	_channel.create_message("nou");
			// TODO add way to stop bot (probably only have for  debugging purposes)
			// if (content == "~stop") bot.yield;
		});

	bot.run();
	//bot.yield();
	std::cout << "Press any key to continue...\n";
	std::cin.ignore();
}