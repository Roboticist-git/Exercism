namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
enum class AccountStatus {
    troll,
    guest,
    user,
    mod
};
// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
enum class Action {
    read,
    write,
    remove
};
// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
bool display_post(AccountStatus poster, AccountStatus viewer) {
    if (poster == AccountStatus::troll && viewer == AccountStatus::troll) {
        return true;
    }
    if (poster == AccountStatus::troll || viewer == AccountStatus::troll) {
        return false;
    }
    return true;
};
// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
bool permission_check(Action action, AccountStatus status) {
    switch (action) {
        case Action::read:
            return true; // All accounts can read
        case Action::write:
            return status == AccountStatus::user || status == AccountStatus::mod || status == AccountStatus::troll;
        case Action::remove:
            return status == AccountStatus::mod;
        default:
            return false;
    }
};
// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
bool valid_player_combination(AccountStatus player1, AccountStatus player2) {
    // Гости не могут играть
    if (player1 == AccountStatus::guest || player2 == AccountStatus::guest) {
        return false;
    }
    // Тролли только с троллями
    if (player1 == AccountStatus::troll || player2 == AccountStatus::troll) {
        return player1 == AccountStatus::troll && player2 == AccountStatus::troll;
    }
    // Все остальные могут играть вместе
    return true;
}

int get_priority(AccountStatus status) {
    // mod > user > guest > troll
    switch (status) {
        case AccountStatus::mod:   return 3;
        case AccountStatus::user:  return 2;
        case AccountStatus::guest: return 1;
        case AccountStatus::troll: return 0;
    }
    return -1; // на всякий случай
}
// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
bool has_priority(AccountStatus first, AccountStatus second) {
    return get_priority(first) > get_priority(second);
}

}  // namespace hellmath