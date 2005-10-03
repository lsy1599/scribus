#ifndef SVGPLUG_H
#define SVGPLUG_H

#include <qobject.h>
#include <qdom.h>
#include "pluginapi.h"
#include "loadsaveplugin.h"

class QString;
class ScribusApp;
class PageItem;
class Page;

class PLUGIN_API SVGExportPlugin : public LoadSavePlugin
{
	Q_OBJECT

	public:
		// Standard plugin implementation
		SVGExportPlugin();
		virtual ~SVGExportPlugin();
		virtual bool run(QString target = QString::null);
		virtual const QString fullTrName() const;
		virtual const AboutData* getAboutData() const;
		virtual void deleteAboutData(const AboutData* about) const;
		virtual void languageChange();
		virtual QValueList<FormatSupport> supportedFormats() const;
		virtual bool fileSupported(QIODevice* file) const;

		// Special features (none)
};

extern "C" PLUGIN_API int svgexplugin_getPluginAPIVersion();
extern "C" PLUGIN_API ScPlugin* svgexplugin_getPlugin();
extern "C" PLUGIN_API void svgexplugin_freePlugin(ScPlugin* plugin);

class SVGExPlug : public QObject
{
    Q_OBJECT

public:
    SVGExPlug( QString fName );
    ~SVGExPlug();

private:
		void ProcessPage(Page *Seite, QDomDocument *docu, QDomElement *elem);
		QString SetClipPathImage(PageItem *ite);
		QString SetClipPath(PageItem *ite);
		QString FToStr(double c);
		QString IToStr(int c);
		void SetTextProps(QDomElement *tp, struct ScText *hl);
		QString SetFarbe(QString farbe, int shad);
		QString GetMultiStroke(struct SingleLine *sl, PageItem *Item);
		int GradCount;
		int ClipCount;
};

#endif // CMSPLUG_H
