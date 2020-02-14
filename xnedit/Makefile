# $NetBSD$

DISTNAME=	xnedit-${VERS}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xnedit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/xnedit/
COMMENT=	Fork of NEdit with Unicode support and antialiased text
LICENSE=	gnu-gpl-v2
VERS=		1.1.0

USE_LANGUAGES=	c99

WRKSRC=			${WRKDIR}/xnedit
BUILD_TARGET=		netbsd
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PREFIX}/share/doc/xnedit

SUBST_CLASSES+=			fix-include
SUBST_STAGE.fix-include=	pre-configure
SUBST_MESSAGE.fix-include=	Fixing include Xft.h.
SUBST_FILES.fix-include=	util/fontsel.c
SUBST_FILES.fix-include+=	source/textP.h
SUBST_FILES.fix-include+=	source/textDisp.h
SUBST_FILES.fix-include+=	source/nedit.h
#SUBST_FILES.fix-include+=	Microline/XmL/XmL.c
SUBST_SED.fix-include=		-e 's,Xft/Xft.h>,X11/&,'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/xnedit ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/xnc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xnedit.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xnedit.1
	${INSTALL_MAN} ${WRKSRC}/doc/xnc.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xnedit-nc.1
.for f in README ReleaseNotes
	 ${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/xnedit
.endfor
.for f in faq.txt NEdit.ad
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/share/doc/xnedit
.endfor

.include "../../converters/libiconv/buildlink3.mk"
# Not needed. Indirect dependency included via libXft
#.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
# Doesn't work with modular X (and is wrong anyway according to documentation)
#.include "../../mk/x11.buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
