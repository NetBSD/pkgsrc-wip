# $NetBSD: Makefile,v 1.8 2012/10/05 08:44:03 asau Exp $
#

DISTNAME=	pdb2ldif-1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.uslinux.net/software/packages/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.uslinux.net/software/pkginfo.php?pkg=pdb2ldif
COMMENT=	Converts Palm Address Book PDB files into an LDAP-usable LDIF file

DEPENDS+=	p5-Palm>=1.3.0:../../databases/p5-Palm

NO_BUILD=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdb2ldif ${DESTDIR}${PREFIX}/bin/pdb2ldif

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
