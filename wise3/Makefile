# $NetBSD$

PKGNAME=	wise-3
DISTNAME=	master
CATEGORIES=	biology
MASTER_SITES=	https://github.com/birney/wise3/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://github.com/birney/wise3/archive/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

.include "../../devel/glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

WRKSRC=		${WRKDIR}/wise3-master/src
MAKE_FILE=	makefile


INSTALLATION_DIRS+=	bin

post-extract:
	cd ${WRKSRC} && ${MAKE} clean
	${RM} -f ${WRKSRC}/models/porewise

pre-build:
	echo "XXX - the build will fail; that is ok; make install anyway"

pre-install:
	cd ${WRKSRC}/models && ${MAKE} porewise

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/models/porewise ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"

xxx:
	${MAKE} clean-depends clean
	${MAKE}
