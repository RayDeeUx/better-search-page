#include <Geode/modify/LevelSearchLayer.hpp>

using namespace geode::prelude;

class $modify(MyLevelSearchLayer, LevelSearchLayer) {
	static void onModify(auto& self) {
		(void) self.setHookPriority("LevelSearchLayer::init", -3001);
	}
	void moveStuff() {
		const bool isTitlesHidden = Mod::get()->getSettingValue<bool>("hide-titles");

		auto winSize = CCDirector::get()->getWinSize();

		CCNode* levelSearchBg = this->getChildByID("level-search-bg");
		CCNode* levelSearchBarBg = this->getChildByID("level-search-bar-bg");
		CCNode* searchBar = this->getChildByID("search-bar");

		CCNode* quickSearchTitle = this->getChildByID("quick-search-title");
		CCNode* quickSearchBg = this->getChildByID("quick-search-bg");
		CCNode* quickSearchMenu = this->getChildByID("quick-search-menu");

		CCNode* filtersTitle = this->getChildByID("filters-title");
		CCNode* difficultyFiltersBg = this->getChildByID("difficulty-filters-bg");
		CCNode* difficultyFilterMenu = this->getChildByID("difficulty-filter-menu");

		CCNode* lengthFiltersBg = this->getChildByID("length-filters-bg");
		CCNode* lengthFilterMenu = this->getChildByID("length-filter-menu");

		if (isTitlesHidden) {
			quickSearchTitle->setVisible(false);
			filtersTitle->setVisible(false);
		}

		if (!isTitlesHidden) quickSearchTitle->setPositionY(winSize.height - 20.0f);
		quickSearchBg->setPositionY(isTitlesHidden ? winSize.height - 75.0f : quickSearchTitle->getPositionY() - 69.5f);
		quickSearchMenu->setPositionY(quickSearchBg->getPositionY() - 28.0f);

        float dfbgPos = difficultyFiltersBg->getPositionY();

		if (!isTitlesHidden) filtersTitle->setPositionY(quickSearchBg->getPositionY() - 68.0f);
		difficultyFiltersBg->setPositionY(isTitlesHidden ? quickSearchBg->getPositionY() - 91.0f : filtersTitle->getPositionY() - 37.0f);
		
		float filterMenuPosY = difficultyFilterMenu->getPositionY() + (difficultyFiltersBg->getPositionY() - dfbgPos);
		
		difficultyFilterMenu->setPositionY(filterMenuPosY);

		lengthFiltersBg->setPositionY(difficultyFiltersBg->getPositionY() - 51.0f);
		lengthFilterMenu->setPositionY(filterMenuPosY);

		levelSearchBg->setPositionY(30.0f);
		static_cast<CCScale9Sprite*>(levelSearchBg)->setColor(ccColor3B{0, 36, 91});
		levelSearchBarBg->setPositionY(levelSearchBg->getPositionY());
		searchBar->setPositionY(levelSearchBg->getPositionY());
		// just... no. why??
		/*
		auto searchButtonMenu = this->getChildByID("search-button-menu");
		searchButtonMenu->setLayout(
			RowLayout::create()
        		->setAxisAlignment(AxisAlignment::End)
				->setGap(7.0f)
		);
		searchButtonMenu->setContentWidth(levelSearchBg->getContentWidth() - 11.0f);
		searchButtonMenu->setPositionY(levelSearchBg->getPositionY());
		searchButtonMenu->updateLayout();
		*/
	}
	bool init(int p0) {
		if (!LevelSearchLayer::init(p0)) return false;

		Loader::get()->queueInMainThread([this] {
			Loader::get()->queueInMainThread([this] {
				Loader::get()->queueInMainThread([this] {
					Loader::get()->queueInMainThread([this] {
						Loader::get()->queueInMainThread([this] {
							Loader::get()->queueInMainThread([this] {
								Loader::get()->queueInMainThread([this] {
									MyLevelSearchLayer::moveStuff();
								});
							});
						});
					});
				});
			});
		});

		return true;
	}
};
