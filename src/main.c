#include "webview/webview.h"
#include "html.c"
#include <stddef.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine,
                   int nCmdShow) {
  (void)hInst;
  (void)hPrevInst;
  (void)lpCmdLine;
  (void)nCmdShow;
#else
int main(void) {
#endif
  webview_t w = webview_create(0, NULL);
  webview_set_title(w, "16-9=");
  webview_set_size(w, 400, 350, WEBVIEW_HINT_FIXED);
  
  char html[site_index_html_len + 1];
  strncpy(html, (const char *)site_index_html, site_index_html_len);
  html[site_index_html_len] = '\0';
  webview_set_html(w, html);

  webview_run(w);
  webview_destroy(w);
  return 0;
}