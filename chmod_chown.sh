#!/bin/bash
#by suliangliang on 2022-08-02
#item:chmod chown
chmod u+rwx *.sh */*.sh              #modify 1
chmod g-x *.sh && chmod g+rw *.sh
chmod g-x */*.sh && chmod g+rw */*.sh
chmod o-wx *.sh && chmod o+r *.sh
chmod o-wx */*.sh && chmod o+r */*.sh
chown sll:root *.sh && chown sll:root */*.sh
