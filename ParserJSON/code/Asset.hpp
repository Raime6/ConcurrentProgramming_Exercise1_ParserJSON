
/**
*
*	Open Source Code
*
*	Author: Xavier Canals
*
**/



#include <filesystem>
#include <string>



namespace ParserJson
{
	using std::filesystem::path;
	using std::string;

	class Asset
	{
	private:

		path basePath;

	private:

		Asset() = default;

		Asset(const Asset&) = delete;
		Asset(const Asset&&) = delete;
		Asset& operator = (const Asset&) = delete;
		Asset& operator = (const Asset&&) = delete;

	public:

		static Asset& instance()
		{
			static Asset asset;
			return asset;
		}

	public:

		void initialize(const string& executablePath)
		{
			#if defined NDEBUG
			basePath = path{ executablePath }.parent_path() / "assets";
			#else
			basePath = path{ "../../assets" };
			#endif

		}

		path getAssetPath(const string& fileName)
		{
			return basePath / fileName;
		}
	};

	extern Asset& asset = Asset::instance();
}
