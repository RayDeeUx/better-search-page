#include <Geode/modify/LevelSearchLayer.hpp>

#define IS_PAGES_API Loader::get()->isModLoaded("alphalaneous.pages_api")
#define IS_CLEANER_MENU Loader::get()->isModLoaded("devcmb.cleanermenu")
#define GET_CLEANER_MENU Loader::get()->getLoadedMod("devcmb.cleanermenu")

using namespace geode::prelude;

class $modify(LevelSearchLayer) {
	void onEnter() {
		LevelSearchLayer::onEnter();
		log::info("logged onEnter from LSL");
	}
	bool init(int p0) {
		if (!LevelSearchLayer::init(p0)) return false;

		auto isTitlesHidden = Mod::get()->getSettingValue<bool>("hide-titles");

		auto winSize = CCDirector::get()->getWinSize();

		auto levelSearchBg = this->getChildByID("level-search-bg");
		auto levelSearchBarBg = this->getChildByID("level-search-bar-bg");
		auto searchBar = this->getChildByID("search-bar");
		auto searchButtonMenu = this->getChildByID("search-button-menu");

		auto quickSearchTitle = this->getChildByID("quick-search-title");
		auto quickSearchBg = this->getChildByID("quick-search-bg");
		auto quickSearchMenu = this->getChildByID("quick-search-menu");

		auto filtersTitle = this->getChildByID("filters-title");
		auto difficultyFiltersBg = this->getChildByID("difficulty-filters-bg");
		auto difficultyFilterMenu = this->getChildByID("difficulty-filter-menu");

		auto lengthFiltersBg = this->getChildByID("length-filters-bg");
		auto lengthFilterMenu = this->getChildByID("length-filter-menu");

		if (isTitlesHidden) {
			quickSearchTitle->setVisible(false);
			filtersTitle->setVisible(false);
		}

		if (!isTitlesHidden) quickSearchTitle->setPositionY(winSize.height - 20.0f);
		quickSearchBg->setPositionY(isTitlesHidden ? winSize.height - 75.0f : quickSearchTitle->getPositionY() - 69.5f);
		quickSearchMenu->setPositionY(quickSearchBg->getPositionY() - 28.0f);

        auto dfbgPos = difficultyFiltersBg->getPositionY();

		if (!isTitlesHidden) filtersTitle->setPositionY(quickSearchBg->getPositionY() - 68.0f);
		difficultyFiltersBg->setPositionY(isTitlesHidden ? quickSearchBg->getPositionY() - 91.0f : filtersTitle->getPositionY() - 37.0f);
		
		auto filterMenuPos = difficultyFilterMenu->getPositionY() + (difficultyFiltersBg->getPositionY() - dfbgPos);
		
		difficultyFilterMenu->setPositionY(filterMenuPos);

		lengthFiltersBg->setPositionY(difficultyFiltersBg->getPositionY() - 51.0f);
		lengthFilterMenu->setPositionY(filterMenuPos);

		levelSearchBg->setPositionY(30.0f);
		static_cast<CCScale9Sprite*>(levelSearchBg)->setColor(ccColor3B{0, 36, 91});
		levelSearchBarBg->setPositionY(levelSearchBg->getPositionY());
		searchBar->setPositionY(levelSearchBg->getPositionY());
		// just... no. why??
		/*
		searchButtonMenu->setLayout(
			RowLayout::create()
        		->setAxisAlignment(AxisAlignment::End)
				->setGap(7.0f)
		);
		*/
		searchButtonMenu->setContentWidth(levelSearchBg->getContentWidth() - 11.0f);
		searchButtonMenu->setPositionY(levelSearchBg->getPositionY());
		searchButtonMenu->updateLayout();

		return true;
	}
};
