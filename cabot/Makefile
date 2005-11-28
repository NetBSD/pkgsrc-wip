# $NetBSD: Makefile,v 1.3 2005/11/28 00:27:23 rillig Exp $

DISTNAME=		cabot-0.0.20050504
CATEGORIES=		misc security
MASTER_SITES=		http://alioth.debian.org/download.php/1034/

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://cabot.alioth.debian.org/
COMMENT=		Scripts that help managing a PGP keysigning process

DEPENDS+=	p5-GnuPG-Interface>=0.34:../../security/p5-GnuPG-Interface
DEPENDS+=	p5-Class-MethodMaker>=2.07:../../devel/p5-Class-MethodMaker
DEPENDS+=	gnupg>=1.4.2:../../security/gnupg

USE_TOOLS+=		gmake
USE_PKGINSTALL=         yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PERL5_CONFIGURE=	no
REPLACE_PERL=		Cabot.pm ca-createsendout ca-recv ca-sendout ca-dosign

EGDIR=			${PREFIX}/share/examples/cabot
CONF_FILES+=            ${EGDIR}/cabot.conf ${PKG_SYSCONFDIR}/cabot.conf
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
MAKE_ENV+=		PKG_PERL5_SITELIB=${PERL5_INSTALLVENDORLIB:Q}

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/cabot.conf ${EGDIR}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
