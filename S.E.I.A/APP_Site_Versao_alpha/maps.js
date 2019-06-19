function get_location() {
  navigator.geolocation.getCurrentPosition(show_map);
}

get_location();