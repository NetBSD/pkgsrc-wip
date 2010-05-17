# $NetBSD: Makefile,v 1.2 2010/05/17 00:35:29 jym-netbsd Exp $
#

DISTNAME=	awl-${LIBAWL_VERSION}
PKGNAME=	php-libawl-${LIBAWL_VERSION}
LIBAWL_VERSION=	0.42
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rscds/}

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	http://andrew.mcmillan.net.nz/node/91/
COMMENT=	"PHP Andrew's Web Libraries"
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=       php>=5.2.0:../../lang/php5

INSTALLATION_DIRS=	${LIBAWLDIR} ${LIBAWLDIR}/inc ${LIBAWLDIR}/dba

do-install:
	cd ${WRKSRC}/dba;					\
       	for f in *; do						\
		${INSTALL_DATA} "$$f"				\
		    ${DESTDIR}${PREFIX}/${LIBAWLDIR}/dba;	\
	done;

	cd ${WRKSRC}/inc;					\
       	for f in *; do						\
		${INSTALL_DATA} "$$f"				\
		    ${DESTDIR}${PREFIX}/${LIBAWLDIR}/inc;	\
	done;

.include "../../wip/php-libawl/Makefile.common"
.include "../../mk/bsd.pkg.mk"
