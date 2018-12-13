/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/grit/brave_generated_resources.h"
#include "chrome/grit/generated_resources.h"
#include "content/public/browser/web_ui_data_source.h"

// Forward declarations needed due to extensions_ui.cc being patched with this
// function name.
namespace extensions {
namespace {
struct LocalizedString;
void BraveAddLocalizedStringsBulk(content::WebUIDataSource* html_source,
                                  const LocalizedString localized_strings[],
                                  size_t num_strings);
} // namespace
} // namespace extensions

#include "../../../../../../chrome/browser/ui/webui/extensions/extensions_ui.cc"

namespace extensions {

namespace {

void BraveAddLocalizedStringsBulk(content::WebUIDataSource* html_source,
                                  const LocalizedString localized_strings[],
                                  size_t num_strings) {
  // Pacify unused function error.
  AddLocalizedStringsBulk(html_source, {}, 0);

  for (size_t i = 0; i < num_strings; i++) {
    if (localized_strings[i].id == IDS_MD_EXTENSIONS_ITEM_CHROME_WEB_STORE) {
      html_source->AddLocalizedString(localized_strings[i].name,
        IDS_MD_EXTENSIONS_BRAVE_ITEM_CHROME_WEB_STORE);
    } else
    if (localized_strings[i].id == IDS_MD_EXTENSIONS_ITEM_SOURCE_WEBSTORE) {
      html_source->AddLocalizedString(localized_strings[i].name,
        IDS_MD_EXTENSIONS_BRAVE_ITEM_SOURCE_WEBSTORE);
    } else
      html_source->AddLocalizedString(localized_strings[i].name,
                                      localized_strings[i].id);
  }

  html_source->AddLocalizedString("moreExtensions",
    IDS_MD_EXTENSIONS_BRAVE_MORE_EXTENSIONS);
}

} // namespace

} // namespace extensions
