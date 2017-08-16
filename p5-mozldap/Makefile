# $NetBSD: Makefile,v 1.3 2012/10/04 19:12:08 asau Exp $
#

DISTNAME=	perl-mozldap-1.5.2
PKGNAME=	p5-mozldap-1.5.2
CATEGORIES=	security perl5
#MASTER_SITES=	${MASTER_SITE_MOZILLA:=directory/perldap/releases/1.5.2/src/}
MASTER_SITES=	ftp://ftp.mozilla.org/pub/mozilla.org/directory/perldap/releases/1.5.2/src/

MAINTAINER=	evaldo@gardenali.biz
#HOMEPAGE=	http://www.mozilla.org/directory/perldap.html
COMMENT=	Mozilla implementation of LDAP support libraries for Perl
LICENSE=	gnu-gpl-v1 OR gnu-lgpl-v2.1 OR mpl-1.1

MAKE_ENV+=	LDAPSDKDIR=${PREFIX}
MAKE_ENV+=	LDAPSDKINCDIR=${PREFIX}/include/ldap
MAKE_ENV+=	LDAPSDKLIBDIR=${PREFIX}/lib
MAKE_ENV+=	LDAPSDKSSL=Y
MAKE_ENV+=	LDAPPR=Y
MAKE_ENV+=	NSPRDIR=${PREFIX}
MAKE_ENV+=	NSPRINCDIR=${PREFIX}/include/nspr
MAKE_ENV+=	NSPRLIBDIR=${PREFIX}/lib
MAKE_ENV+=	NSSDIR=${PREFIX}
MAKE_ENV+=	NSSLIBDIR=${PREFIX}/lib

PERL5_PACKLIST=	auto/Mozilla/LDAP/API/.packlist

.include "../../lang/perl5/module.mk"
.include "../../wip/mozldap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
