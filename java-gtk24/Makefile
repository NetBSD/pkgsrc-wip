# $NetBSD: Makefile,v 1.4 2005/04/11 21:13:19 tvierling Exp $
#

DISTNAME=		libgtk-java-2.6.2
PKGNAME=		java-gtk24-2.6.2
CATEGORIES=		wip x11
MASTER_SITES=		ftp://ftp.gnome.org/pub/GNOME/sources/libgtk-java/2.6/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		ftp://ftp.gnome.org/pub/GNOME/sources/libgtk-java/2.6/
COMMENT=		Java bindings for GTK+2

DEPENDS+=       jikes-[0-9]*:../../lang/jikes

GNU_CONFIGURE=YES
USE_GNU_TOOLS+=make
CONFIGURE_ARGS+=--without-gcj-compile
MAKE_ENV+=CLASSPATH=${PKG_JAVA_HOME}/jre/lib/rt.jar

# db2html isn't 
SUBST_CLASSES=db au cp
SUBST_FILES.db=macros/am_path_docbook.m4
SUBST_SED.db=-e 's,db2html,true,g' -e 's,docbook2html,true,g'
SUBST_STAGE.db=pre-configure

SUBST_FILES.au=autogen.sh
SUBST_SED.au=-e 's,\./,\#,'
SUBST_STAGE.au=post-extract

SUBST_FILES.cp=src/Makefile
SUBST_SED.cp=-e 's,$$(JAVA_SOURCE_PATH),java:${PKG_JAVA_HOME}/jre/lib/rt.jar,'
SUBST_STAGE.cp=pre-build

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
