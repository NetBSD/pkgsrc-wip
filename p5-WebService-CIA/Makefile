# $NetBSD: Makefile,v 1.3 2012/10/04 19:12:05 asau Exp $
#

DISTNAME=		WebService-CIA-1.4
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/I/IM/IMALPASS/}

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		http://search.cpan.org/CPAN/authors/id/I/IM/IMALPASS/
COMMENT=		Information from the CIA World Factbook

DEPENDS+=		p5-MLDBM>=2.01:../../databases/p5-MLDBM
DEPENDS+=		p5-DB_File>=1.8:../../databases/p5-DB_File
DEPENDS+=		p5-Storable>=2.0:../../devel/p5-Storable
DEPENDS+=		p5-libwww>=2.0:../../www/p5-libwww
DEPENDS+=		p5-Crypt-SSLeay>=0:../../security/p5-Crypt-SSLeay

PKG_DESTDIR_SUPPORT=	none

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/WebService/CIA/.packlist
MAKE_PARAMS=		< /dev/null # no user-interaction

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
