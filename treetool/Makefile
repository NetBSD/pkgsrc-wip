# $NetBSD: Makefile,v 1.6 2012/10/16 13:07:56 asau Exp $

DISTNAME=	treetool2.0.2
PKGNAME=	treetool-2.0.2
CATEGORIES=	biology
#MASTER_SITES=	http://iubio.bio.indiana.edu/soft/molbio/unix/treetool/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=
COMMENT=	Treetool is for displaying, editing, and printing phylogenetic trees

DECOMPRESS_CMD=	${CAT}
USE_TOOLS+=	gmake

MAKE_ENV+=	CFLAGS="-g -O0"

post-extract:
	${FIND} ${WRKSRC} -name '*.o' -exec ${RM} -f {} \;

do-configure:
	for f in Makefile graphics/font.c treetool/Makefile; do \
		${TEST} -r ${WRKSRC}/$$f.in || ${MV} ${WRKSRC}/$$f ${WRKSRC}/$$f.in; \
		${SED} < ${WRKSRC}/$$f.in > ${WRKSRC}/$$f \
			-e 's:@PREFIX@:${PREFIX}:' \
			-e 's:@X11BASE@:${X11BASE}:'; \
	done

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/treetool_release/treetool ${DESTDIR}${PREFIX}/bin/treetool
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/treetool
	${INSTALL_DATA} ${WRKSRC}/treetool_release/README ${DESTDIR}${PREFIX}/share/doc/treetool/README
	${INSTALL_DATA} ${WRKSRC}/treetool_release/user.manual ${DESTDIR}${PREFIX}/share/doc/treetool/user.manual
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/misc/treetool
	${INSTALL_DATA} ${WRKSRC}/treetool_release/font_map ${DESTDIR}${PREFIX}/share/misc/treetool/font_map

.include "../../x11/xview-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
