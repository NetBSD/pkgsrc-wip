# $NetBSD: Makefile,v 1.2 2004/10/26 22:56:51 thomasklausner Exp $
#

DISTNAME=	pkg_notify-0.1
CATEGORIES=	pkgtools
MASTER_SITES=	http://imil.net/NetBSD/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/
COMMENT=	Notifies package maintainer when a new version is available

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww

WRKSRC=		${WRKDIR}/pkg_notify
USE_BUILDLINK3= yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_PERL5=	yes

CONF_FILES=	${PKG_SYSCONFDIR}/pkg_notify.list

INSTALLATION_DIRS=	bin

post-extract:
	${SED} 's%\/usr\/pkgsrc%${PKGSRCDIR}%g' ${WRKSRC}/pkg_notify |\
	${SED} 's%\/usr\/pkg%${LOCALBASE}%g' 				\
				 > ${WRKSRC}/pkg_notify.tmp &&		\
	${MV} ${WRKSRC}/pkg_notify.tmp ${WRKSRC}/pkg_notify;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_notify ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
