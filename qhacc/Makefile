# $NetBSD: Makefile,v 1.4 2005/04/11 21:15:24 tvierling Exp $
#

DISTNAME=		qhacc-3.0
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=qhacc/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://qhacc.sourceforge.net/
COMMENT=		The Q Home Accountant for personal bookkeeping

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_GNU_TOOLS=		make

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/qhacc
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/qhacc

post-patch:
	for f in `${FIND} ${WRKSRC} -name "Makefile.in"` ; do \
		${SED} -e 's|$$(prefix)/plugins|$$(libdir)/plugins|g' \
			$$f > $$f.patch && \
		${MV} $$f.patch $$f; \
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/qhacc
	${INSTALL_DATA} ${WRKSRC}/contrib/easysetup/[a-t]* ${PREFIX}/share/examples/qhacc/
	${INSTALL_DATA_DIR} ${PREFIX}/share/qhacc
	${INSTALL_DATA} ${WRKSRC}/qm/qhacc_es_ES.qm ${PREFIX}/share/qhacc/

.include "../../x11/qt3-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
