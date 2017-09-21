# $NetBSD: Makefile,v 1.1 2015/02/10 08:29:01 thomasklausner Exp $

DISTNAME=	RT-Authen-ExternalAuth-0.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RT/}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/RT-Authen-ExternalAuth/
COMMENT=	RT extension for external authentication methods
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-ldap
DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay
DEPENDS+=	rt4-[0-9]*:../../devel/rt4

# TODO: broken -- installs to var!
PERL5_PACKLIST=		auto/RT/Authen/ExternalAuth/.packlist

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
MAKE_ENV+=		RTHOME=${PREFIX}/share/rt4/lib

# checks permissions of file from rt4 and dies if different user
PKG_DESTDIR_SUPPORT=	destdir

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
