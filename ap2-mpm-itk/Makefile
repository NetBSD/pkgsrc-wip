# $NetBSD$

DISTNAME=	mpm-itk-2.4.7-04
CATEGORIES=	www security
MASTER_SITES=	http://mpm-itk.sesse.net/

MAINTAINER=	root@zta.lk
HOMEPAGE=	http://mpm-itk.sesse.net/
COMMENT=	Apache module that allows to run each vhost under a separate uid and gid
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes

PKG_APACHE_ACCEPTED=	apache24

APACHE_MODULE=          yes
APACHE_MODULE_NAME=     mod_mpm_itk.la

.include "../../mk/apache.module.mk"
.include "../../mk/bsd.pkg.mk"
