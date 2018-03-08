## What is this?

OW Escape Bind is a really simple program that listens for a specified key event and will bind it to your escape. It will only fire to the Overwatch window.
I mean, that's all it does really.

## Who is this for?

Anyone without an escape key for some reason.

## Limitations

While the event is only sent to the Overwatch, it can be triggered from anywhere. For example, if you bind escape to `;`, alt+tab out into Notepad or something and press `;`, it will essentially be pressing escape in Overwatch for you.
Another small limitation is it doesn't support binding to every key possible yet.

## Compiling

Being very basic all you should really need is mingw. Compiling is as simple as 

```
gcc -o bind escbind.c
```

![alt text](https://github.com/poltergasm/OW-Escape-Bind/blob/master/bind.png)