# $NetBSD$

.include "../../wip/nginx-modular/version.mk"

PKGNAME=	nginx-modular-${NGINX_VERSION}
DISTNAME=	nginx-${NGINX_VERSION}
CATEGORIES=	www
MASTER_SITES=	http://nginx.org/download/
DISTFILES=	${DEFAULT_DISTFILES}

MAINTAINER=	osa@NetBSD.org
HOMEPAGE=	https://nginx.org/
COMMENT=	Lightweight HTTP server and mail proxy server
LICENSE=	2-clause-bsd

.include "../../wip/nginx-modular/Makefile.common"

PKG_USERS_VARS+=	NGINX_USER
PKG_GROUPS_VARS+=	NGINX_GROUP
PKG_GROUPS=		${NGINX_GROUP}
PKG_USERS=		${NGINX_USER}:${NGINX_GROUP}

PKG_GECOS.${NGINX_USER}=	NGINX server user
PKG_HOME.${NGINX_USER}=		${NGINX_DATADIR}
PKG_SHELL.${NGINX_USER}=	${NOLOGIN}

.include "options.mk"

EGFILES+=		fastcgi.conf fastcgi_params koi-utf koi-win \
			mime.types nginx.conf win-utf

RCD_SCRIPTS=		nginx

INSTALLATION_DIRS+=	${PKGMANDIR}/man8 sbin share/examples/nginx/conf \
			share/examples/nginx/html
MAKE_DIRS+=		${NGINX_PIDDIR}
OWN_DIRS=		${NGINX_LOGDIR}
OWN_DIRS_PERMS+=	${NGINX_DATADIR} ${NGINX_USER} ${NGINX_GROUP} 0700

BUILD_TARGET=		build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objs/nginx ${DESTDIR}${PREFIX}/sbin/nginx
.for file in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/conf/${file} ${DESTDIR}${EGDIR}/conf/${file}
.endfor
	${INSTALL_DATA} ${WRKSRC}/html/50x.html ${DESTDIR}${EGDIR}/html/50x.html
	${INSTALL_DATA} ${WRKSRC}/html/index.html ${DESTDIR}${EGDIR}/html/index.html
	${INSTALL_MAN} ${WRKSRC}/objs/nginx.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
.if !empty(PKG_OPTIONS:Mperl)
	${INSTALL_LIB_DIR} ${DESTDIR}${PERL5_INSTALLVENDORARCH}/auto/nginx
	${INSTALL_LIB} ${WRKSRC}/objs/src/http/modules/perl/blib/arch/auto/nginx/nginx.${SOEXT} \
		${DESTDIR}${PERL5_INSTALLVENDORARCH}/auto/nginx
	${INSTALL_DATA} ${WRKSRC}/objs/src/http/modules/perl/blib/lib/nginx.pm \
		${DESTDIR}${PERL5_INSTALLVENDORARCH}
.endif
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/libexec/nginx
	(cd ${WRKSRC}/objs/ && ${FIND} . -name '*.so' -maxdepth 1 -type f \
		-exec ${INSTALL_PROGRAM} {} ${DESTDIR}${PREFIX}/libexec/nginx \;)

.include "../../mk/bsd.pkg.mk"
