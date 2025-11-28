def increment_password(pw: str) -> str:
    pw_list = list(pw)
    i = len(pw_list) - 1
    while i >= 0:
        if pw_list[i] == 'z':
            pw_list[i] = 'a'
            i -= 1
        else:
            pw_list[i] = chr(ord(pw_list[i]) + 1)
            break
    return ''.join(pw_list)

def has_no_forbidden_letters(pw: str) -> bool:
    return all(c not in "iol" for c in pw)

def has_straight_of_three(pw: str) -> bool:
    for i in range(len(pw) - 2):
        if ord(pw[i]) + 1 == ord(pw[i+1]) and ord(pw[i]) + 2 == ord(pw[i+2]):
            return True
    return False

def has_two_non_overlapping_pairs(pw: str) -> bool:
    pairs = set()
    i = 0
    while i < len(pw) - 1:
        if pw[i] == pw[i+1]:
            pairs.add(pw[i])
            i += 2  # overslaan zodat paren niet overlappen
        else:
            i += 1
    return len(pairs) >= 2

def generate_new_password(current_password: str) -> str:
    pw = current_password
    while True:
        pw = increment_password(pw)
        if (has_no_forbidden_letters(pw) and
            has_straight_of_three(pw) and
            has_two_non_overlapping_pairs(pw)):
            return pw

if __name__ == "__main__":
    print(generate_new_password("hxbxwxba"))
    print(generate_new_password("hxbxxyzz"))
