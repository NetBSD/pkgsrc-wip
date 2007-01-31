# $NetBSD: Makefile,v 1.1.1.1 2007/01/31 13:29:12 marmfield Exp $

DISTNAME=	Jcode-2.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	# not defined
CATEGORIES=	japanese converters perl5 wip
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Jcode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Perl library for Japanese charset handler

WRKSRC=			${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PERL5_INSTALLVENDORLIB}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/Jcode.pm ${PERL5_INSTALLVENDORLIB}/Jcode.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
