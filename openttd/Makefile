# $NetBSD: Makefile,v 1.1.1.1 2004/08/27 21:56:11 froz Exp $

DISTNAME=	openttd-0.3.3
CATEGORIES=	games x11
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=openttd/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	froz@icix.org
HOMEPAGE=	http://www.openttd.com/
COMMENT=	Open source clone of Transport Tycoon Deluxe

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
MAKE_ENV+=	WITH_NETWORK=1 USE_HOMEDIR=1 PERSONAL_DIR=.openttd GAME_DATA_DIR=${PREFIX}/share/openttd/

USE_X11=	yes

MAKE_ENV+=	X11BASE=${X11BASE}

DATA_DIR= 	${PREFIX}/share/openttd

post-patch:
	${SED} -e "s:@PREFIX@:"${PREFIX}":g" ${FILESDIR}/openttd > \
		${WRKSRC}/openttd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttd ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/openttd ${PREFIX}/bin
	@${INSTALL_DATA_DIR} ${DATA_DIR}
	@${INSTALL_DATA_DIR} ${DATA_DIR}/lang
	@${INSTALL_DATA_DIR} ${DATA_DIR}/data
	@${INSTALL_DATA_DIR} ${DATA_DIR}/docs
	${INSTALL_DATA} -m 644 ${WRKSRC}/lang/*.lng ${DATA_DIR}/lang
	${INSTALL_DATA} -m 644 ${WRKSRC}/data/* ${DATA_DIR}/data
	${INSTALL_DATA} -m 644 ${WRKSRC}/readme.txt ${DATA_DIR}/docs
	${INSTALL_DATA} -m 644 ${WRKSRC}/changelog.txt ${DATA_DIR}/docs
	${INSTALL_DATA} -m 644 ${WRKSRC}/docs/Manual.txt ${DATA_DIR}/docs

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
