#include "SDK\em4sdk.hpp"


class Mission01 : public Mission01
{
	enum Incident
	{
		INC_VUBLECH,
		INC_VU_P,
		INC_P_SEARCH,
		INC_ARMED,
		INC_HOOLIGAN,
		INC_HELPLESS_P,
		INC_EVENT,
		INC_DISTURB,
		INC_ARGUE,
		INC_DEMO,

		INC_LIQUOR,
		INC_CONFUSED_P,
		INC_CHILDREN_DANGER,
		INC_BURGLARY,
		INC_WARRANT,
		INC_STABBING,
		INC_PICKPOCKETING,
		INC_ROBBERY,
		INC_BILKING,
		INC_DAMAGE,

		INC_INJURY,
		INC_SUICIDE,
		INC_TRAFFIC_CONTROL,
		INC_DRUGDEALER,
		INC_FIGHT,
		INC_DOOR_OPENING,
		INC_TRUANCY,
		INC_DOG_FOUND,
		INC_CARTHEFT,
		INC_CRAZY_DRIVER,

		INC_CORPSE,
		INC_PROTECTION,
		INC_P_PROTECTION,
		INC_POST_BURGLARY,
		INC_EXPLOSIVE,
		INC_ARSON,
		INC_CHILDREN,
		INC_LESSONS,
		INC_FIRE,
	};

	Mission01() {}
	~Mission01() {}

	

	void Start()
	{
		Mission::PlayHint("foobar");
	}

	void Update()
	{
	}
};