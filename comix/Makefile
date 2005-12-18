# $NetBSD: Makefile,v 1.1.1.1 2005/12/18 13:54:18 hugor Exp $
#

DISTNAME=		comix-2.2.1
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=comix/}

MAINTAINER=		hugor@users.sourceforge.net
HOMEPAGE=		http://comix.sourceforge.net/index.html
COMMENT=		Image viewer specifically designed to handle comic books

DEPENDS+=		unrar-[0-9]*:../../archivers/unrar
DEPENDS+=		hicolor-icon-theme-[0-9]*:../../graphics/hicolor-icon-theme
DEPENDS+=		py23-gtk2>=2.6:../../x11/py-gtk2
NO_BUILD=		yes

MANCOMPRESSED=		yes

do-configure:

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} install.py install --installdir ${PREFIX}
post-install:
	cd ${LOCALBASE}/bin && ${SED} -e "1s|python|${PYTHONBIN}|" comix > comix.hlp
	${MV} ${LOCALBASE}/bin/comix.hlp ${LOCALBASE}/bin/comix
	${CHMOD} 755 ${LOCALBASE}/bin/comix


.include		"../../lang/python/application.mk"
.include		"../../x11/py-gtk2/buildlink3.mk"
.include		"../../mk/bsd.pkg.mk"
