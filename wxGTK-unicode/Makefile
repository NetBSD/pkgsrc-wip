# $NetBSD: Makefile,v 1.6 2010/06/13 22:47:21 thomasklausner Exp $

.include "Makefile.common"

PKGREVISION=		1
COMMENT=		GTK-based unicode implementation of the wxWidgets GUI library

# conflicts with non unicode version
CONFLICTS+=	wxGTK-[0-9]*

BUILD_TARGET=	all
INSTALL_TARGET=	install

INSTALLATION_DIRS=	${DOCDIR}

post-build:
	set -e; cd ${WRKSRC}/locale; \
	for lang in ca cs da de el es fi fr hu id it ja nl pl ru sl sv tr uk \
	    zh_CN zh_TW; do \
		${TOOLS_PATH.msgfmt} -c -o $${lang}.mo $${lang}.po; \
	done
	set -e; cd ${WRKSRC}/locale/msw; \
	for lang in it; do \
	    ${TOOLS_PATH.msgfmt} -c -o $${lang}.mo $${lang}.po; \
	done

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/licence.txt ${DESTDIR}${DOCDIR}

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
