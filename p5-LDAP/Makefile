# $NetBSD: Makefile,v 1.3 2015/04/12 14:22:45 makoto Exp $
#

DISTNAME=	perldap-1.4.1
# convert 'ldap' part into uppercase
PKGNAME=	p5-${DISTNAME:S/per//tu}
CATEGORIES=	devel perl5 databases
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=directory/perldap/ancient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/directory/perldap.html
COMMENT=	Perl5 module to build LDAP clients with perl
LICENSE=	mpl-1.0

PERL5_PACKLIST=	auto/Mozilla/LDAP/API/.packlist

MAKE_ENV+=	LDAPSDKDIR=${BUILDLINK_PREFIX.ldapsdk}
MAKE_ENV+=	LDAPSDKSSL="no"
MAKE_ENV+=	LDAPV3ON="yes"

#include "../../x11/kdelibs3/buildlink3.mk"
.include "../../devel/ldapsdk/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
