# $NetBSD: Makefile,v 1.1.1.1 2003/11/05 05:01:54 mpasternak Exp $
#

DISTNAME=		cal3d_cally-0.9
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cal3d/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			TheCallyDemo-2.9.zip

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://cal3d.sourceforge.net/
COMMENT=		Demonstration of cal3d library

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cal3d=${PREFIX}
CONFIGURE_ARGS+=	--with-glut=${PREFIX}
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

DATADIR=		${PREFIX}/share/cal3d_cally/data
WRKDATADIR=		${WRKDIR}/thecallydemo-2.9/data
PATCHDATA=		cally.cfg paladin.cfg skeleton.cfg

pre-configure:
	cd ${WRKSRC} && ./autogen.sh
	
post-patch:
	${CP} ${WRKSRC}/src/demo.cpp ${WRKSRC}/src/demo.cpp.pkgsrc
	${SED} -e 's|@@DATADIR@@|${DATADIR}|g' ${WRKSRC}/src/demo.cpp.pkgsrc > \
		${WRKSRC}/src/demo.cpp
		
	for f in ${PATCHDATA}; do \
		${CP} ${WRKDATADIR}/$$f ${WRKDATADIR}/$$f.pkgsrc && \
		${SED} -e 's|@@DATADIR@@|${DATADIR}|g' ${WRKDATADIR}/$$f.pkgsrc > \
			${WRKDATADIR}/$$f; && \
		${RM} ${WRKDATADIR}/$$f.pkgsrc; \
		done

do-install:
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/cal3d_cally ${PREFIX}/bin/
	cd ${WRKDATADIR} && ${PAX} -rw -pe [a-z]* ${DATADIR}

.include "../../wip/cal3d/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
