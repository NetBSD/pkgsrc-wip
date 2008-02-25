# $NetBSD: Makefile,v 1.3 2008/02/25 17:56:14 tnn2 Exp $

.include "Makefile.common"

PKGREVISION=		0
COMMENT=		GTK-based unicode implementation of the wxWidgets GUI library

# conflicts with non unicode version
CONFLICTS+=	wxGTK-[0-9]*

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
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCDIR}/LICENSE

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
