// #include <type_traits>
// // template <bool AddOrRemoveRef> struct Fun_;
// template <typename T, bool AddOrRemove> struct Fun_;
// // template <> struct Fun_<true> {
// //   template <typename T> using type = std::add_lvalue_reference<T>;
// // };
// // template <> struct Fun_<false> {
// //   template <typename T> using type = std::remove_reference<T>;
// // };
// template <typename T> struct Fun_<T, true> {
//   using type = std::add_lvalue_reference<T>;
// };
// template <typename T> struct Fun_<T, false> {
//   using type = std::remove_reference<T>;
// };
// template <typename T, bool AddOrRemove>
// // template <bool AddOrRemove>
// using Fun = typename Fun_<T, AddOrRemove>::type;

// template <typename T> using Res_ = Fun<T, false>;
// template <typename T> using Res = typename Res_<T>::type;
// Res_<int &>::type a = 1;
// Res<int &&> c = 1;
