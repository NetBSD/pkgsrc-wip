# $NetBSD: Makefile,v 1.1.1.1 2005/01/14 10:56:47 imilh Exp $
#

DISTNAME=	pkg_notify-0.4.2
CATEGORIES=	pkgtools
MASTER_SITES=	http://imil.net/NetBSD/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/
COMMENT=	Notifies package maintainer when a new version is available

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww

WRKSRC=		${WRKDIR}/pkg_notify

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILDLINK=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_PERL5=	yes

INSTALLATION_DIRS=	bin

USE_PKGINSTALL=	yes

EXAMPLEDIR= ${PREFIX}/share/examples/${PKGBASE}
DOCDIR= ${PREFIX}/share/doc/${PKGBASE}

CONF_FILES= ${EXAMPLEDIR}/${PKGBASE}.list ${PKG_SYSCONFDIR}/${PKGBASE}.list

SUBST_CLASSES+=	pkg_notify
SUBST_MESSAGE.pkg_notify=	"Setting up hardcoded path."
SUBST_STAGE.pkg_notify=		post-patch
SUBST_FILES.pkg_notify=		pkg_notify README
SUBST_SED.pkg_notify=		-e 's|/usr/pkgsrc|${PKGSRCDIR}|'	\
				-e 's|/usr/pkg|${LOCALBASE}|g'		\
				-e 's|/usr/bin/make|${MAKE}|g'		\
				-e 's|/usr/pkg/bin/perl|${PERL5}|g'

MESSAGE_SUBST+=	DOCDIR=${DOCDIR}

do-install:
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_notify ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PKGBASE}.list ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
